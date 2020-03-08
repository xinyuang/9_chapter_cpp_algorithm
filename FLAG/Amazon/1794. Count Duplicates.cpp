//1794. Count Duplicates
//unordered_map store duplica


class Solution {
public:
	/**
	 * @param nums: a integer array
	 * @return: return an integer denoting the number of non-unique(duplicate) values
	 */
	vector<int> CountDuplicates(vector<int>& nums) {
		// write your code here
		unordered_map<int, int> mp;
		unordered_set<int> used;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			mp[nums[i]]++;
			if (mp[nums[i]] > 1 && !used.count(nums[i]))
			{
				res.push_back(nums[i]);
				used.insert(nums[i]);
			}
		}
		return res;
	}
};