Input: [1, 2, 3, 3, 4, 5]
	Output : True
	Explanation : You can split them into two subsequences :
	   [1, 2, 3]
	   [3, 4, 5]

class Solution {
public:
	/**
	 * @param nums: a list of integers
	 * @return: return a boolean
	 */
	bool isPossible(vector<int>& nums) {
		// write your code here
		unordered_map<int, int> freq;
		unordered_map<int, int> last;
		for (int i = 0; i < nums.size(); i++) freq[nums[i]]++;
		for (int i = 0; i < nums.size(); i++)
		{
			if (freq[nums[i]] == 0) continue;
			if (last.count(nums[i] - 1) && last[nums[i] - 1] > 0)
			{
				last[nums[i] - 1]--;
				last[nums[i]]++;
			}
			else if (freq.count(nums[i] + 1) && freq.count(nums[i] + 2) && freq[nums[i] + 1] && freq[nums[i] + 2])
			{
				freq[nums[i] + 1]--;
				freq[nums[i] + 2]--;
				last[nums[i] + 2]++;
			}
			else return false;
			freq[nums[i]]--;
		}
		return true;
	}
};