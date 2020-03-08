//471. Top K Frequent Words
//1. unordered_map count freq
//2. min_heap store top k
//3. reverse result

class Solution {
public:
	/**
	 * @param words: an array of string
	 * @param k: An integer
	 * @return: an array of string
	 */
	vector<string> topKFrequentWords(vector<string>& words, int k) {
		// write your code here
		if (k > words.size()) return {};
		unordered_map<string, int> mp;
		for (int i = 0; i < words.size(); i++)
		{
			mp[words[i]]++;
		}
		typedef pair<string, int> pt;
		class cmp {
		public:
			bool operator()(const pt& a, const pt& b)
			{
				if (a.second == b.second) return a.first < b.first;
				return a.second > b.second;
			}
		};
		priority_queue<pt, vector<pt>, cmp> min_heap;
		for (auto ele : mp)
		{
			min_heap.push(ele);
			if (min_heap.size() > k) {
				min_heap.pop();
			}
		}
		vector<string> res;
		while (!min_heap.empty()) {
			res.push_back(min_heap.top().first);
			min_heap.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};