// 1473. Paint House III

// 1. dp[i][j][c] means in [0:i] houses have j neighbor, the i th house paint in c color
// 2. if i th house already painted dp[i][j][c], for loop prev color, set INF, dp[i][j]k] or dp[i][j-1][k]
// 3. if i th house nor paint, for loop color, dp[i][j][c] = dp[i][j-1][k] + cost or dp[i][j][k] + cost

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(target+1,vector<int>(n+1,INT_MAX)));
        for(int c = 0; c < n; c++) dp[0][0][c+1] = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < target; j++)
            {
                for(int c = 0; c < n; c++)
                {
                    if(houses[i] != 0)
                    {
                        int prev_c = houses[i];
                        if(c+1 != prev_c) dp[i+1][j+1][c+1] = INT_MAX;
                        else
                        {
                            for(int k = 0; k < n; k++)
                            {
                                if(k != c)
                                {
                                    dp[i+1][j+1][c+1]= min(dp[i+1][j+1][c+1], dp[i][j][k+1]);
                                }
                                else
                                {
                                    dp[i+1][j+1][c+1] = min(dp[i+1][j+1][c+1], dp[i][j+1][k+1]);
                                }
                            }
                        }
                    }
                    else
                    {
                        for(int k = 0; k < n; k++)
                        {
                            if(c != k)
                            {
                                if(dp[i][j][k+1] == INT_MAX) continue;
                                dp[i+1][j+1][c+1] = min(dp[i+1][j+1][c+1], dp[i][j][k+1] + cost[i][c]);
                            }
                            else
                            {
                                if(dp[i][j+1][k+1]== INT_MAX) continue;
                                dp[i+1][j+1][c+1] = min(dp[i+1][j+1][c+1], dp[i][j+1][k+1] + cost[i][c]);
                            }
                        }
                    }
                }
            }
        }
        int min_cost = INT_MAX;
        for(int c = 0; c < n; c++) min_cost = min(min_cost, dp[m][target][c+1]);
        if(min_cost == INT_MAX) return -1;
        return min_cost;
    }
};