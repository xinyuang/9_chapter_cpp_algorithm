// 540. Single Element in a Sorted Array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return -1;
        if(nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() - 1;
        while(left + 1 < right)
        {
            int mid = (right - left) / 2 + left;
            // cout << mid << " " << right << " " << left << endl;
            if(nums[mid] == nums[mid+1])
            {
                if((right - mid - 1) % 2 == 0)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else if(mid - 1 >= 0 && nums[mid-1] == nums[mid])
            {
                if((right - mid) % 2 == 0)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }              
            }
            else
            {
                return nums[mid];
            }
        }
        // cout << "?" << left << " " << right << endl;
        if(left == 0 && nums[left] != nums[left+1]) return nums[left];
        if(left != 0 && nums[left] != nums[left-1] && nums[left] != nums[left+1]) return nums[left];
        if(right+1 == nums.size() && nums[right-1] != nums[right]) return nums[right];
        if(nums[right] != nums[right-1] && nums[right] != nums[right+1]) return nums[right];
        
        return -1;
    }
};