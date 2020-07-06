// 1044. Largest Plus Sign
// dp[i][j]   =>  vertical:         up close,  down close
//                horizontal:       left close, right close
//          dp[i][j] = min(4 direction) + char16_t
// solution 1:  dp[k][i][j]  store left,right,up,down closest dist for point(i,j)
//              Time O(n^2)      Space O(n^2)

// solution 2:  if mines list is sparse enough
//              Binary search the closest dist  (logk)  ~ O(1)
//              Time O(n^2*logK)      Space O(1)

class Solution {
private:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
public:
    /**
     * @param N: size of 2D grid
     * @param mines: in the given list
     * @return: the order of the plus sign
     */
    
    
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
        // Write your code here
        vector<vector<vector<int>>> dp(4,vector<vector<int>>(N+2,vector<int>(N+2,0)));
        vector<vector<int>> GD(N+2,vector<int>(N+2,1));
        for(int i = 0; i < mines.size(); i++)
        {
            int x = mines[i][0] + 1, y = mines[i][1] + 1;
            GD[x][y] = 0;
        }
        for(int k = 0; k < 4; k++)
        {
            if(k%2 == 0)
            {
                for(int i = 2; i <= N; i++)
                {
                    for(int j = 2; j <= N; j++)
                    {
                        dp[k][i][j] = (GD[i+dx[k]][j + dy[k]] == 0) ? 0 : dp[k][i+dx[k]][j + dy[k]] + 1;
                    }
                }
            }
            else
            {
                for(int i = N-1; i >= 1; i--)
                {
                    for(int j = N-1; j >= 1; j--)
                    {
                        dp[k][i][j] = (GD[i + dx[k]][j + dy[k]] == 0) ? 0 : dp[k][i + dx[k]][j + dy[k]] + 1;
                    }
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                if(GD[i][j] == 0) continue;
                int len = INT_MAX;
                for(int k = 0; k < 4; k++) len = min(len,dp[k][i][j]);
                res = max(res,len + 1);
            }
        }
        return res;

    }
};


class Solution {
public:
    /**
     * @param N: size of 2D grid
     * @param mines: in the given list
     * @return: the order of the plus sign
     */
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines) {
        // Write your code here

        unordered_map<int,set<int>> rows;
        unordered_map<int,set<int>> cols;
        for(int i = 0; i < mines.size(); i++)
        {
            rows[mines[i][0]].insert(mines[i][1]);
            cols[mines[i][1]].insert(mines[i][0]);
        }
        
        int res = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                vector<int> cur_row(rows[i].begin(),rows[i].end());
                vector<int> cur_col(cols[j].begin(),cols[j].end());
                int row_min = getMinDist(-1,N,cur_row,j);
                int col_min = getMinDist(-1,N,cur_col,i);
                int cur_min = min(row_min,col_min) + 1;
                res = max(res,cur_min);
            }
        }
        return res;
        
    }
    
    int getMinDist(int start, int end, vector<int>& cur, int idx)
    {
        if(cur.size() != 0)
        {
            auto it = lower_bound(cur.begin(),cur.end(),idx);
            if(it == cur.end())
            {
                start = cur.back();
            }
            else
            {
                end = *it;
                start = *(--it);
            }
        }
        int dist = min((idx - start- 1),(end - idx - 1));
        return dist;
    }
};