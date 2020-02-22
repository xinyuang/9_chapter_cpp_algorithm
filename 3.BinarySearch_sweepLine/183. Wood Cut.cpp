//183. Wood Cut
//1. target legth range[0, max(Li)]
//2. if (canCut(mid)) left = mid, else right = mid

class Solution {
public:
	/**
	 * @param L: Given n pieces of wood with length L[i]
	 * @param k: An integer
	 * @return: The maximum length of the small pieces
	 */
	int woodCut(vector<int>& L, int k) {
		// write your code here
		int left = 0, right = 0;
		for (int i = 0; i < L.size(); i++) right = max(right, L[i]);
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (canCut(mid, L, k)) left = mid;
			else right = mid;
		}
		if (canCut(right, L, k)) return right;
		return left;
	}

	bool canCut(int target, vector<int>& L, int k) {
		int count = 0;
		for (int i = 0; i < L.size(); i++)
		{
			count += (L[i] / target);
		}
		return count >= k;
	}
};