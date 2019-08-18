class Solution {
public:
	/**
	 * @param nums: the given array
	 * @param k: the given k
	 * @return: the k most frequent elements
	 */
	struct compare {
		bool operator()(pair<int, int> a, pair<int, int> b)
		{
			return b.second < a.second;
		}
	};
	vector<int> topKFrequent(vector<int>& nums, int k) {
		// Write your code here
		unordered_map<int, int> map; // nums - frequency
		for (int i = 0; i < nums.size(); i++)
		{
			map[nums[i]]++;
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>, compare> min_heap;
		for (pair<int, int> item : map)
		{
			min_heap.push(item);
			if (min_heap.size() > k)
			{
				min_heap.pop();
			}
		}
		vector<int> res;
		while (!min_heap.empty())
		{
			pair<int, int> cur = min_heap.top();
			res.push_back(cur.first);
			min_heap.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};