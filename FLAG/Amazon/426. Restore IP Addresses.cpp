// 426. Restore IP Addresses

// if(next_v > 255) continue;
// if(next[0] == '0' && next.size() > 1) continue;

class Solution {
public:
    /**
     * @param s: the IP string
     * @return: All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string &s) {
        // write your code here
        vector<string> res;
        vector<int> path;
        dfs(res,path,s,0);
        return res;
    }
    
    void dfs(vector<string>& res, vector<int>& path, string& s, int idx)
    {
        if(idx > s.size()) return;
        if(path.size() == 4 && idx == s.size())
        {
            string sub = toString(path);
            res.push_back(sub);
            return;
        }
        
        for(int i = 1; i <= 3; i++)
        {
            if(idx + i > s.size()) continue;
            string next = s.substr(idx,i);
            int next_v = stoi(next);
            if(next_v > 255) continue;
            if(next[0] == '0' && next.size() > 1) continue;
            path.push_back(next_v);
            dfs(res,path,s, idx + i);
            path.pop_back();
        }
    }
    
    string toString(vector<int>& path)
    {
        string res;
        for(int i = 0; i < path.size(); i++)
        {
            res += to_string(path[i]) + ".";
        }
        res.pop_back();
        return res;
    }
};