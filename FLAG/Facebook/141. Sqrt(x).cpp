// 141. Sqrt(x)
// binary search, use mid < x / mid to avoid overflow


class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        int left = 0, right = x;
        while(left + 1 < right)
        {
            int mid = (right - left) / 2 + left;
            if(mid < x/mid) left = mid;
            else right = mid;
        }
        if(right <= x/right) return right;
        return left;
    }
};