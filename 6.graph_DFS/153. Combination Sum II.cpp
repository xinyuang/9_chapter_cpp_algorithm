//  combination sum  (sort, backtrack, remove duplicates)
//  [2, 3, 4, 7], target = 6
//	[[2,2,2], [3,3], [2,4]]
//  [3,4,4,5]
// The same repeated number may be chosen from candidates unlimited number of times.
class Solution {
public:
	/**
	 * @param candidates: A list of integers
	 * @param target: An integer
	 * @return: A list of lists of integers
	 */
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		// write your code here
		vector<int> com;
		vector<vector<int>> res;
		sort(candidates.begin(), candidates.end());
		helper(candidates, target, res, com, 0);
		return res;
	}

	void helper(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& com, int start)
	{
		if (target < 0) return;
		if (target == 0)
		{
			res.push_back(com);
			return;
		}
		for (int i = start; i < nums.size(); i++)
		{
			if (i != 0 && nums[i] == nums[i - 1] && i > start) continue;
			com.push_back(nums[i]);
			helper(nums, target - nums[i], res, com, i);
			com.pop_back();
		}
	}
};

// The same repeated number may NOT be chosen from candidates unlimited number of times.
class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
	vector<vector<int>> combinationSum2(vector<int>& num, int target) {
		// write your code here
		vector<vector<int>> res;
		vector<int> path;
		sort(num.begin(), num.end());
		backtrack(res, path, num, target, 0);
		return res;
	}

	void backtrack(vector<vector<int>>& res, vector<int>& path, vector<int>& num, int target, int start)
	{
		if (target == 0)
		{
			res.push_back(path);
			return;
		}
		if (target < 0) return;
		for (int i = start; i < num.size(); i++)
		{
			if (i != 0 && num[i] == num[i - 1] && i > start) continue;
			path.push_back(num[i]);
			backtrack(res, path, num, target - num[i], i + 1);
			path.pop_back();
		}
	}
};