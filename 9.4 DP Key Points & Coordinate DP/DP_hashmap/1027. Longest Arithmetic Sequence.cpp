// 1027. Longest Arithmetic Sequence

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int,unordered_map<int,int>> dp;
        int res = 0;
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = i+1; j < A.size(); j++)
            {
                int diff = A[j] - A[i];
                dp[diff][j] = (dp[diff].count(i)) ? dp[diff][i] + 1 : 2;
                res = max(res, dp[diff][j]);
            }
        }
        return res;
    }
};