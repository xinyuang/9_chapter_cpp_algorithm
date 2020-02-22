//438. Copy Books II
//
//1. target = min(max(ti * #book)) range is[min ~max(ti) * # book / #people]
//2. if (canFinish(mid)) right = mid, else left = mid
//3. canFinish(mid), sum(mid / t[i]) >= #book

class Solution {
public:
	/**
	 * @param n: An integer
	 * @param times: an array of integers
	 * @return: an integer
	 */
	int copyBooksII(int n, vector<int>& times) {
		// write your code here
		if (n == 0) return 0;
		if (times.size() == 0) return INT_MAX;
		int lower = INT_MAX, upper = INT_MIN;
		for (int i = 0; i < times.size(); i++)
		{
			lower = min(times[i], lower);
			upper = max(times[i], upper);
		}
		int left = lower, right = n * upper;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (findT(mid, times, n)) right = mid;
			else left = mid;
		}
		if (findT(left, times, n)) return left;
		return right;
	}

	bool findT(int target, vector<int>& times, int n)
	{
		int count = 0;
		for (int i = 0; i < times.size(); i++)
		{
			count += (target / times[i]);
		}
		return count >= n;
	}
};