// 433. Number of Islands

class Solution {
private:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        
        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 0) continue;
                count++;
                BFS(i,j,grid);
            }
        }
        return count;
    }
    
    void BFS(int x, int y, vector<vector<bool>>& grid)
    {
        queue<pair<int,int>> q;
        q.push({x,y});
        while(!q.empty())
        {
            auto cur = q.front(); q.pop();
            for(int i = 0; i < 4; i++)
            {
                int xx = cur.first + dx[i];
                int yy = cur.second + dy[i];
                if(!is_valid(xx,yy,grid)) continue;
                if(grid[xx][yy])
                {
                    grid[xx][yy] = 0;
                    q.push({xx,yy});
                }
            }
        }
    }
    
    bool is_valid(int x, int y, vector<vector<bool>>& grid)
    {
        if(x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size()) return true;
        return false;
    }
};