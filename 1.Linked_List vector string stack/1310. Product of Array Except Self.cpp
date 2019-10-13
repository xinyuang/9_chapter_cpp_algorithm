// Product of Array Except Self

// prefix product [i] * postfix product[i]  , the product is not include nums[i]
//       1,2,3,2,4
//  pre  1,1,2,6,12
//  pos 48 24 8 4 1
class Solution {
public:
	/**
	 * @param nums: an array of integers
	 * @return: the product of all the elements of nums except nums[i].
	 */
	vector<int> productExceptSelf(vector<int>& nums) {
		// write your code here
		if (nums.size() == 0) return {};
		vector<int> res(nums.size(), 0);
		vector<int> preMul(nums.size(), 0);
		preMul[0] = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			preMul[i] = preMul[i - 1] * nums[i - 1];
		}
		int postMul = 1;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			res[i] = preMul[i] * postMul;
			postMul *= nums[i];
		}
		return res;
	}
};

// brutal solution
class Solution {
public:
	vector<int> productExceptSelf(vector<int> nums) {
		// write your solution here
		vector<int> res;
		for (int i = 0; i < nums.size(); i++)
		{
			int multi = 1;
			for (int j = 0; j < nums.size(); j++)
			{
				if (j == i) continue;
				multi *= nums[j];
			}
			res.push_back(multi);
		}
		return res;
	}
};