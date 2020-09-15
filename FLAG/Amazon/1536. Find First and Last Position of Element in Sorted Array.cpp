//1536. Find First and Last Position of Element in Sorted Array

class Solution {
public:
    /**
     * @param nums: the array of integers
     * @param target: 
     * @return: the starting and ending position
     */
    vector<int> searchRange(vector<int> &nums, int target) {
        // Write your code here.
        int first = findFirst(nums,target);
        int last = findLast(nums,target);
        return {first,last};
    }
    
    int findFirst(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left + 1 < right)
        {
            int mid = (right - left) / 2 + left;
            if(nums[mid] < target) left = mid;
            else right = mid;
        }
        if(nums[left] == target) return left;
        if(nums[right] == target) return right;
        return -1;
    }
    
    int findLast(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left + 1 < right)
        {
            int mid = (right - left) / 2 + left;
            if(nums[mid] > target) right = mid;
            else left = mid;
        }
        if(nums[right] == target) return right;
        if(nums[left] == target) return left;
        return -1;
    }
};



class Solution {
public:
	/**
	 * @param nums: the array of integers
	 * @param target:
	 * @return: the starting and ending position
	 */
	vector<int> searchRange(vector<int>& nums, int target) {
		// Write your code here.
		int left = 0, right = nums.size() - 1;
		while (left + 1 < right)
		{
			int mid = (right - left) / 2 + left;
			if (nums[mid] < target) left = mid;
			else right = mid;
		}
		int start = -1, end = -1;
		if (nums[left] == target) start = left;
		else if (nums[right] == target) start = right;
		for (int i = start; i < nums.size(); i++)
		{
			if (nums[i] != target) break;
			end = i;
		}
		return { start,end };
	}
};
