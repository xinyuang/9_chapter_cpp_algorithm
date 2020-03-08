//587. Two Sum - Unique pairs
//1. unordered_set, visited
//1. sort array, two pointers

class Solution {
public:
	/**
	 * @param nums: an array of integer
	 * @param target: An integer
	 * @return: An integer
	 */
	int twoSum6(vector<int>& nums, int target) {
		// write your code here
		unordered_set<int> visited;
		unordered_set<int> st;
		int count = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (st.count(target - nums[i]) && !visited.count(target - nums[i])) {
				count++;
				visited.insert(target - nums[i]);
				visited.insert(nums[i]);
			}
			st.insert(nums[i]);
		}
		return count;
	}
};

class Solution {
public:
	/**
	 * @param nums: an array of integer
	 * @param target: An integer
	 * @return: An integer
	 */
	int twoSum6(vector<int>& nums, int target) {
		// write your code here
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1;
		int count = 0;
		while (left < right)
		{
			if (nums[left] + nums[right] == target)
			{
				left++;
				right--;
				count++;
				while (nums[left] == nums[left - 1]) left++;
				while (nums[right] == nums[right + 1]) right--;
			}
			else if (nums[left] + nums[right] < target)
			{
				left++;
			}
			else right--;
		}
		return count;
	}
};