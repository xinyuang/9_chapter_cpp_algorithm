// 1016. Minimum Swaps To Make Sequences Increasing

//  A    i-1  i
//  B    i-1  i
//  if ori array already increasing,  
//             keep = last_keep
//             swap = last_swap + 1     (because last time you swapped, you need to swap it back)                   
//  if swap i position also increasing,
//             keep = min(keep, last_swap)   (if you don't swap current i, it should be transferred from the last swapped state at i-1)
//             swap = min(swap, last_keep + 1)  ( if you swap current i, it should transferred from the last keep state at i-1)     
class Solution {
public:
    /**
     * @param A: an array
     * @param B: an array
     * @return: the minimum number of swaps to make both sequences strictly increasing
     */
    int minSwap(vector<int> &A, vector<int> &B) {
        // Write your code here
        int last_keep = 0;
        int last_swap = 1;
        for(int i = 1; i < A.size(); i++)
        {
            int keep = INT_MAX;
            int swap = INT_MAX;            
            if(A[i] > A[i-1] && B[i] > B[i-1])
            {
                keep = last_keep;
                swap = last_swap + 1;
            }
            if(A[i] > B[i-1] && B[i] > A[i-1])
            {
                keep = min(keep,last_swap);
                swap = min(swap,last_keep+1);
            }
            last_keep = keep;
            last_swap = swap;
        }
        return min(last_keep,last_swap);
    }
};