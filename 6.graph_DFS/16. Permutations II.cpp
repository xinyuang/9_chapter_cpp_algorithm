// permutation (sort, backtrack, remove duplicates)
//   [1,2',2'']
//   [1,2',2'']   [1,2'',2'] x
class Solution {
public:
	/*
	 * @param :  A list of integers
	 * @return: A list of unique permutations
	 */
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		// write your code here
		vector<vector<int>> res;
		vector<int> path;
		vector<int> visited(nums.size(), 0);
		sort(nums.begin(), nums.end());
		backtrack(res, path, nums, visited);
		return res;
	}
	void backtrack(vector<vector<int>>& res, vector<int>& path, vector<int>& nums, vector<int> visited)
	{
		if (path.size() == nums.size())
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (visited[i] == 1) continue;
			if (i != 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
			path.push_back(nums[i]);
			visited[i] = 1;
			backtrack(res, path, nums, visited);
			path.pop_back();
			visited[i] = 0;
		}
	}
};