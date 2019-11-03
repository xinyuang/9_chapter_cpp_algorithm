// Merge K Sorted Arrays
// mergeSort
class Solution {
public:

	std::vector<int> mergekSortedArrays(std::vector<std::vector<int>>& arrays,
		int start, int end)
	{
		if (start == end)
			return arrays[start];

		int mid = start + (end - start) / 2;
		std::vector<int> left_array = mergekSortedArrays(arrays, start, mid);
		std::vector<int> right_array = mergekSortedArrays(arrays, mid + 1, end);

		return merge2SortedArrays(left_array, right_array);
	}

	std::vector<int> merge2SortedArrays(std::vector<int>& A,
		std::vector<int>& B)
	{
		std::vector<int> result(A.size() + B.size());

		int i = 0, j = 0, res_pos = 0;
		while (i < A.size() && j < B.size())
			result[res_pos++] = A[i] < B[j] ? A[i++] : B[j++];

		while (i < A.size())
			result[res_pos++] = A[i++];

		while (j < B.size())
			result[res_pos++] = B[j++];

		return result;
	}

	/**
	 * @param arrays: k sorted integer arrays
	 * @return: a sorted array
	 */
	vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
		return mergekSortedArrays(arrays, 0, arrays.size() - 1);
	}
};

// priority_queue
class Solution {
public:
	/**
	 * @param arrays: k sorted integer arrays
	 * @return: a sorted array
	 */
	vector<int> mergekSortedArrays(vector<vector<int>>& arrays) {
		// write your code here
		struct compare {
			bool operator()(pair<int, int> a, pair<int, int> b)
			{
				return b.second < a.second;
			}
		};
		int n = arrays.size();
		int idx[n] = { 0 };
		priority_queue<pair<int, int>, vector<pair<int, int>>, compare> min_heap;  // array_idx, val
		for (int i = 0; i < n; i++)
		{
			if (arrays[i].size() == 0) continue;
			min_heap.push(make_pair(i, arrays[i][0]));
		}
		vector<int> res;
		while (!min_heap.empty())
		{
			pair<int, int> cur = min_heap.top(); min_heap.pop();
			int array_idx = cur.first;
			int cur_val = cur.second;
			res.push_back(cur_val);
			idx[array_idx]++;
			if (idx[array_idx] >= arrays[array_idx].size()) continue;
			min_heap.push(make_pair(array_idx, arrays[array_idx][idx[array_idx]]));
		}
		return res;
	}
};