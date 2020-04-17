//1310. Product of Array Except Self
//preMul[i] * postMul[i] = res[i]

class Solution {
public:
	/**
	 * @param nums: an array of integers
	 * @return: the product of all the elements of nums except nums[i].
	 */
	vector<int> productExceptSelf(vector<int>& nums) {
		// write your code here
		vector<int> preMul(nums.size(), 0);
		vector<int> sufMul(nums.size(), 0);
		vector<int> res(nums.size(), 0);
		preMul[0] = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			preMul[i] = preMul[i - 1] * nums[i - 1];
		}
		sufMul[nums.size() - 1] = 1;
		res[nums.size() - 1] = preMul[nums.size() - 1];
		for (int i = nums.size() - 2; i >= 0; i--)
		{
			sufMul[i] = sufMul[i + 1] * nums[i + 1];
			res[i] = preMul[i] * sufMul[i];
		}
		return res;
	}
};