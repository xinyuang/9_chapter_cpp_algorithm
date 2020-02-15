//543. Kth Largest in N Arrays
//
//1. sort arrays greater<int>()
//2. max_heap, vector<int> idx  to find and store top values

class compare {
public:
	bool operator() (pair<int, int>& a, pair<int, int>& b)
	{
		return a.second < b.second;
	}
};


class Solution {
public:
	/**
	 * @param arrays: a list of array
	 * @param k: An integer
	 * @return: an integer, K-th largest element in N arrays
	 */
	int KthInArrays(vector<vector<int>>& arrays, int k) {
		// write your code here
		for (int i = 0; i < arrays.size(); i++) sort(arrays[i].begin(), arrays[i].end(), greater<int>());
		priority_queue<pair<int, int>, vector<pair<int, int>>, compare> min_heap;  // array_idx, value
		vector<int> idx(arrays.size(), 0);
		for (int i = 0; i < arrays.size(); i++)
		{
			if (arrays[i].size() == 0) continue;
			min_heap.push({ i,arrays[i][0] });
			idx[i]++;
		}
		int count = 0;
		while (!min_heap.empty())
		{
			pair<int, int> cur = min_heap.top(); min_heap.pop();
			count++;
			if (count == k) return cur.second;
			int array_idx = cur.first;
			if (idx[array_idx] < arrays[array_idx].size())
			{
				min_heap.push({ array_idx, arrays[array_idx][idx[array_idx]] });//{array_idx, arrays[array_idx]}
				idx[array_idx]++;
			}
		}
		return -1;
	}
};