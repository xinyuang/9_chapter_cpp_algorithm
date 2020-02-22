//437. Copy Books
//
//1. target = min(max(c1, c2 ... cK)) range is[max(ci), sum(ci)]
//2. if (canFinish(mid)) right = mid, else left = mid
//3. canFinish(mid), maximize every group time <= mid, return #group <= k

class Solution {
public:
	/**
	 * @param pages: an array of integers
	 * @param k: An integer
	 * @return: an integer
	 */
	int copyBooks(vector<int>& pages, int k) {
		// write your code here
		int sum = 0;
		int max_page = 0;
		for (int i = 0; i < pages.size(); i++)
		{
			sum += pages[i];
			max_page = max(max_page, pages[i]);
		}
		int left = max_page, right = sum;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (findT(mid, k, pages)) right = mid;
			else left = mid;
		}
		if (findT(left, k, pages)) return left;
		return right;
	}

	bool findT(int T, int k, vector<int>& pages)
	{
		int count = 0;
		int ptr = 0;
		int cur_task = 0;
		while (ptr < pages.size())
		{
			cur_task = 0;
			while (ptr < pages.size() && cur_task < T)
			{
				cur_task += pages[ptr];
				ptr++;
			}
			if (cur_task > T) ptr--;
			count++;
		}
		if (cur_task > T) count++;
		return k >= count;
	}
};