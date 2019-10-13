// Subsets
// backtrack
class Solution {
public:
	/**
	 * @param nums: A set of numbers
	 * @return: A list of lists
	 */
	vector<vector<int>> subsets(vector<int>& nums) {
		// write your code here
		vector<vector<int>> res;
		vector<int> set;
		sort(nums.begin(), nums.end());
		helper(nums, set, res, 0);
		return res;
	}

	void helper(vector<int>& nums, vector<int>& set, vector<vector<int>>& res, int start)
	{
		res.push_back(set);
		for (int i = start; i < nums.size(); i++)
		{
			set.push_back(nums[i]);
			helper(nums, set, res, i + 1);
			set.pop_back();
		}
	}
};

//  [2,3,5,1,2,6]
//  [1,0,1,1,1,0] each element either select it or not select it
//  total 2^n solution, which is 1 << n;
class Solution {
public:
	/**
	 * @param nums: A set of numbers
	 * @return: A list of lists
	 */
	vector<vector<int>> subsets(vector<int>& nums) {
		// write your code here
		int n = nums.size();
		int range = 1 << n;
		sort(nums.begin(), nums.end());
		vector<int> subset;
		vector<vector<int>> res;
		for (int i = 0; i < range; i++)
		{

			for (int j = 0; j < n; j++)
			{
				if ((i & (1 << j)) != 0)
				{
					subset.push_back(nums[j]);
				}
			}
			res.push_back(subset);
			subset.clear();
		}
		return res;
	}
};