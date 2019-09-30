// Ugly Number

// Priority_queue
class Solution {
public:
	/**
	 * @param n: An integer
	 * @return: return a  integer as description.
	 */

	struct compare {
		bool operator() (long a, long b)
		{
			return b < a;
		}
	};
	int nthUglyNumber(int n) {
		// write your code here
		priority_queue<long long, vector<long long>, compare> q;
		unordered_set<long long> visited;
		vector<int> ugly = { 2,3,5 };
		q.push(1);
		visited.insert(1);
		long long res;
		int idx = 0;
		while (idx < n)
		{
			res = q.top();
			q.pop();
			for (int j = 0; j < 3; j++)
			{
				long long candidate = res * ugly[j];
				if (visited.count(candidate)) continue;
				visited.insert(candidate);
				q.push(candidate);
			}
			idx++;
		}
		return res;
	}
};


// Three pointer
class Solution {
public:
	/**
	 * @param n: An integer
	 * @return: return a  integer as description.
	 */
	int nthUglyNumber(int n) {
		// write your code here
		int ptr[3] = { 0 };
		int ugly[3] = { 2,3,5 };
		vector<int> cur = { 1 };
		while (cur.size() < n)
		{
			int add_idx = -1;
			int cur_min = INT_MAX;
			for (int j = 0; j < 3; j++)
			{
				int candidate = cur[ptr[j]] * ugly[j];
				if (candidate < cur_min)
				{
					cur_min = candidate;
					add_idx = j;
				}
			}
			ptr[add_idx]++;
			if (cur_min <= cur.back()) continue;
			cur.push_back(cur_min);
		}
		return cur.back();
	}
};