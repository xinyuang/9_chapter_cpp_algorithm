//1823. Longest Prefix of Array
//unordered_map store X, Y, if mp[X] >= 1 && mp[X] == mp[Y] update ptr, return ptr

class Solution {
public:
	/**
	 * @param X: a integer
	 * @param Y: a integer
	 * @param nums: a list of integer
	 * @return: return the maximum index of largest prefix
	 */
	int LongestPrefix(int X, int Y, vector<int>& nums) {
		// write your code here
		unordered_map<int, int> mp;
		int longest = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			mp[nums[i]]++;
			if (mp[X] >= 1 && mp[X] == mp[Y]) longest = i;
		}
		return longest;
	}
};