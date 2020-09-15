// 5448. Path Crossing

class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> visited;
        string pos = hash(0,0);
        visited.insert(pos);
        int x = 0, y = 0;
        for(int i = 0; i < path.size(); i++)
        {
            if(path[i] == 'N')
            {
                int xx = x - 1;
                int yy = y;
                string cur = hash(xx,yy);
                if(visited.count(cur)) return true;
                visited.insert(cur);
                x = xx;
                y = yy;
            }
            if(path[i] == 'S')
            {
                int xx = x + 1;
                int yy = y;
                string cur = hash(xx,yy);
                if(visited.count(cur)) return true;
                visited.insert(cur);
                x = xx;
                y = yy;
            }
            if(path[i] == 'E')
            {
                int xx = x;
                int yy = y + 1;
                string cur = hash(xx,yy);
                if(visited.count(cur)) return true;
                visited.insert(cur);
                x = xx;
                y = yy;
            }
            if(path[i] == 'W')
            {
                int xx = x;
                int yy = y - 1;
                string cur = hash(xx,yy);
                if(visited.count(cur)) return true;
                visited.insert(cur);
                x = xx;
                y = yy;
            }
        }
        return false;
    }
    
    string hash(int x, int y)
    {
        return to_string(x) + "," + to_string(y);
    }
};