// Longest Consecutive Sequence
// left right pointer, delete in set if continuous
class Solution {
public:
	/**
	 * @param num: A list of integers
	 * @return: An integer
	 */
	int longestConsecutive(vector<int>& num) {
		// write your code here
		unordered_set<int> set(num.begin(), num.end());
		int ans = 0;
		for (int i = 0; i < num.size(); i++)
		{
			int left = num[i], right = num[i];
			int len = 1;
			while (set.count(left - 1))
			{
				set.erase(left - 1);
				len++;
				left--;
			}
			while (set.count(right + 1))
			{
				set.erase(right + 1);
				len++;
				right++;
			}
			if (len > ans) ans = len;
		}
		return ans;
	}
};