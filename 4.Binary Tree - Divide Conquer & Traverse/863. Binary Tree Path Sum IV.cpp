//863. Binary Tree Path Sum IV
//1. unordered_set store non_leaf
//2. dfs get path(leaf to root) sum


class Solution {
public:
	/**
	 * @param nums: a list of integers
	 * @return: return an integer
	 */
	int pathSum(vector<int>& nums) {
		// write your code here
		sort(nums.begin(), nums.end());
		unordered_set<int> non_leaf;
		int res = 0;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			if (non_leaf.count(nums[i])) continue;
			int path_sum = 0;
			findPath(path_sum, nums[i], nums, non_leaf);
			res += path_sum;
		}
		return res;
	}

	int findPath(int& path_sum, int cur, vector<int>& nums, unordered_set<int>& non_leaf)
	{
		int unit = cur - (cur / 10) * 10;
		path_sum += unit;
		int parent_level = cur / 100 - 1;
		int parent_pos = (cur / 10 % 10 + 1) / 2;
		int parent_range = parent_level * 100 + parent_pos * 10;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] >= parent_range && nums[i] <= parent_range + 9)
			{
				non_leaf.insert(nums[i]);
				findPath(path_sum, nums[i], nums, non_leaf);
			}
		}
	}
};