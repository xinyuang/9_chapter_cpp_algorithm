//1405. Longest Happy String
//1. recursive preprocess swap to ensure a >= b >= c
//2. if b == 0, return min(2, a_number), else alway append 2 a, and 1 b if the number is enough

class Solution {
public:
	string longestDiverseString(int a, int b, int c) {
		string res = getLongest(a, b, c, 'a', 'b', 'c');
		return res;
	}

	string getLongest(int a, int b, int c, char a_c, char b_c, char c_c)
	{
		if (b > a) return getLongest(b, a, c, b_c, a_c, c_c);
		if (c > b) return getLongest(a, c, b, a_c, c_c, b_c);
		if (b == 0) return string(min(a, 2), a_c);
		int use_a = min(2, a);
		int use_b = (a - use_a >= b) ? 1 : 0;
		return string(use_a, a_c) + string(use_b, b_c) + getLongest(a - use_a, b - use_b, c, a_c, b_c, c_c);
	}
};


// Non-recursice use linked list
class myNode {
public:
	char val;
	myNode* next;
	myNode(char v)
	{
		val = v;
		next = nullptr;
	}
};
class Solution {
public:
	string longestDiverseString(int a, int b, int c) {
		unordered_map<char, int> mp = { {'a',a},{'b',b},{'c',c} };
		vector<pair<char, int>> nums = { {'a',a},{'b',b},{'c',c} };
		class compare {
		public:
			bool operator()(const pair<int, int>& a, const pair<int, int>& b)
			{
				if (a.second == b.second) return a.first < b.first;
				return a.second < b.second;
			}
		} com;
		sort(nums.begin(), nums.end(), com);
		char min_c = nums[0].first;
		char second = nums[1].first;
		char max_c = nums[2].first;
		myNode* dummy = new myNode(0);
		myNode* cur = dummy;
		myNode* prev = dummy;
		while (mp[max_c] > 0)
		{
			myNode* node = new myNode(max_c);
			cur->next = node;
			cur = cur->next;
			mp[max_c]--;
		}
		cur = dummy;
		int tmp = 0;
		myNode* lastSecond = nullptr;

		while (mp[second] > 0 && cur && cur->next)
		{
			// cout << cur->val << endl;
			cur = cur->next;
			tmp++;
			if (tmp == 2)
			{
				// insert second
				myNode* pilot = cur->next;
				myNode* node = new myNode(second);
				cur->next = node;
				mp[second]--;
				lastSecond = node;
				cur = node;
				if (!pilot) break;
				node->next = pilot;

				// cout << cur->val << " " << pilot->val << bool(cur->next)<< endl;
				tmp = 0;
			}
		}

		cur = dummy;
		while (mp[second] > 0 && cur && cur->next)
		{
			prev = cur;
			cur = cur->next;
			if (cur && prev->val == cur->val) tmp++;
			else tmp = 1;
			if (tmp == 2)
			{
				// insert second
				myNode* pilot = cur->next;
				myNode* node = new myNode(second);
				cur->next = node;
				mp[second]--;
				cur = node;
				if (!pilot)break;
				node->next = pilot;

				tmp = 0;
			}
		}

		while (mp[second] > 0)
		{
			myNode* node = new myNode(second);
			cur->next = node;
			cur = cur->next;
			mp[second]--;
		}

		cur = lastSecond;
		while (mp[min_c] > 0 && cur && cur->next)
		{
			prev = cur;
			cur = cur->next;
			if (cur && prev->val == cur->val) tmp++;
			else tmp = 1;
			if (tmp == 2)
			{
				// insert second
				myNode* pilot = cur->next;
				myNode* node = new myNode(min_c);
				cur->next = node;
				mp[min_c]--;
				cur = node;
				if (!pilot)break;
				node->next = pilot;

				tmp = 0;
			}
		}

		cur = dummy;
		while (mp[min_c] > 0 && cur && cur->next)
		{
			prev = cur;
			cur = cur->next;
			if (cur && prev->val == cur->val) tmp++;
			else tmp = 1;
			if (tmp == 2)
			{
				// insert second
				myNode* pilot = cur->next;
				myNode* node = new myNode(min_c);
				cur->next = node;
				mp[min_c]--;
				cur = node;
				if (!pilot)break;
				node->next = pilot;

				tmp = 0;
			}
		}

		string res = "";
		cur = dummy;
		tmp = 0;
		while (cur)
		{
			prev = cur;
			cur = cur->next;
			if (cur && prev->val == cur->val) tmp++;
			else tmp = 1;
			if (!cur || tmp > 2) break;
			res.push_back(cur->val);
		}
		return res;

	}
};