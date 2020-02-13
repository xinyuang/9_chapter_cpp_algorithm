//609. Two Sum - Less than or equal to target
//  [1,2,3,4,5,6,7,8]  target 9
//       V V V V x x
//  when left++, right won't move to right

class Solution {
public:
	/**
	 * @param nums: an array of integer
	 * @param target: an integer
	 * @return: an integer
	 */
	int twoSum5(vector<int>& nums, int target) {
		// write your code here
		sort(nums.begin(), nums.end());
		int right = nums.size() - 1;
		int count = 0;
		for (int i = 0; i < right; i++)
		{
			while (right > i && nums[i] + nums[right] > target) right--;
			count += (right - i);
		}
		return count;
	}
};

class Solution {
public:
	/**
	 * @param nums: an array of integer
	 * @param target: an integer
	 * @return: an integer
	 */
	int twoSum5(vector<int>& nums, int target) {
		// write your code here
		sort(nums.begin(), nums.end());
		int left = 0, right = nums.size() - 1;
		int count = 0;
		while (left < right)
		{
			if (nums[left] + nums[right] > target) right--;
			else {
				count += (right - left);
				left++;
			}
		}
		return count;
	}
};