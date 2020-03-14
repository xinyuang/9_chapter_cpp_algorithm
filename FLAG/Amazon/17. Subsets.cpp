//17. Subsets
//backtrack

class Solution {
public:
	/**
	 * @param nums: A set of numbers
	 * @return: A list of lists
	 */
	vector<vector<int>> subsets(vector<int>& nums) {
		// write your code here
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		vector<int> path;
		findSubsets(res, path, nums, 0);
		return res;
	}

	void findSubsets(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, int idx)
	{
		res.push_back(path);
		for (int i = idx; i < nums.size(); i++)
		{
			path.push_back(nums[i]);
			findSubsets(res, path, nums, i + 1);
			path.pop_back();
		}
	}
};