// 1189. Minesweeper

// BFS, update board based on count number
// only when current count == 0, push neighbor to queue

class Solution {
private:
    int dx[8] = {0,1,0,-1,-1,-1,1,1};
    int dy[8] = {1,0,-1,0,-1,1,-1,1};
public:
    /**
     * @param board: a board
     * @param click: the position
     * @return: the new board
     */
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
    // Write your code here
        int x = click[0];
        int y = click[1];
        if(board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return board;
        }
        queue<pair<int,int>> q;
        q.push({x,y});
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        visited[x][y] = 1;
        while(!q.empty())
        {
            pair<int,int> cur = q.front(); q.pop();
            int count = getMines(cur.first, cur.second, board);
            update(cur.first,cur.second,board,count);
            if(count == 0)
            {
                for(int i = 0; i < 8; i++)
                {
                    int xx = cur.first + dx[i];
                    int yy = cur.second + dy[i];
                    if(!is_valid(xx,yy,board)) continue;
                    if(visited[xx][yy] == 1) continue;
                    visited[xx][yy] = 1;
                    if(board[xx][yy] == 'M') continue;
                    q.push({xx,yy});
                } 
            }
   
        }
        return board;
    }
    
    bool is_valid(int x, int y, vector<vector<char>>& board)
    {
        if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) return true;
        return false;
    }
    
    int getMines(int x, int y, vector<vector<char>>& board)
    {
        int count = 0;
        for(int i = 0; i < 8; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(!is_valid(xx,yy,board)) continue;
            if(board[xx][yy] == 'M') count++;
        }
        return count;
    }
    
    int update(int xx, int yy, vector<vector<char>>& board, int count)
    {
        if(count == 0) {
            board[xx][yy] = 'B';
        }
        else board[xx][yy] = '0' + count; 
        return count;
    }

};