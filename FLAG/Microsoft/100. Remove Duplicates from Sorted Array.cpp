//100. Remove Duplicates from Sorted Array
//ptr store non - duplicate number ptr++


class Solution {
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
        if(nums.size() == 0) return 0;
        int ptr = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0 || nums[i] != nums[i-1])
            {
                nums[ptr++] = nums[i];
            }
        }
        return ptr;
    }
};