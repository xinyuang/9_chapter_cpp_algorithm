//437. Copy Books
//
//Binary Search

class Solution {
public:
	/**
	 * @param pages: an array of integers
	 * @param k: An integer
	 * @return: an integer
	 */
	int copyBooks(vector<int>& pages, int k) {
		// write your code here
		if (pages.size() == 0) return 0;
		int min_time = INT_MAX, max_time = 0;
		for (int i = 0; i < pages.size(); i++)
		{
			min_time = min(pages[i], min_time);
			max_time += pages[i];
		}
		int left = min_time, right = max_time;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (canFinish(mid, pages, k)) right = mid;
			else left = mid;
		}
		if (canFinish(left, pages, k)) return left;
		return right;
	}

	bool canFinish(int t, vector<int>& pages, int k)
	{
		int count = 0;
		int idx = 0;
		while (idx < pages.size())
		{
			int left_t = t;
			if (left_t < pages[idx])
			{
				count = k + 1;
				break;
			}
			while (left_t >= pages[idx])
			{
				left_t = left_t - pages[idx];
				idx++;
			}
			count++;
		}
		return count <= k;
	}
};