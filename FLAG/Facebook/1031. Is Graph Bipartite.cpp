// 1031. Is Graph Bipartite?
//  PS, the graph may be a disconnect graph

// BFS 
class Solution {
public:
    /**
     * @param graph: the given undirected graph
     * @return:  return true if and only if it is bipartite
     */
    bool isBipartite(vector<vector<int>> &graph) {
        // Write your code here
        vector<int> father(graph.size(),0);
        vector<int> color(graph.size(), -1);
        queue<int> q;
        for(int i = 0; i < graph.size(); i++){
            father[i] = i;
            for(int j = 0; j < graph[i].size(); j++)
            {
                father[graph[i][j]] = i;
            }
        }
        for(int i = 0; i < father.size(); i++)
        {
            if(father[i] == i)
            {
                q.push(i);
                color[i] = 0;
            }
        }
        while(!q.empty())
        {
            int q_size = q.size();
            for(int i = 0; i < q_size; i++)
            {
                int cur_node = q.front(); q.pop();
                int cur_color = color[cur_node];
                vector<int> neighbor = graph[cur_node];
                for(int j = 0; j < neighbor.size(); j++)
                {
                    int next = neighbor[j];
                    if(color[next] != -1) 
                    {
                        
                        if(color[next] == cur_color) return false;
                        
                        continue;
                    }
                    color[next] = 1 - cur_color;
                    q.push(next);
                }
            }
        }
        return true;
    }
};

// DFS
class Solution {
public:
    /**
     * @param graph: the given undirected graph
     * @return:  return true if and only if it is bipartite
     */
    bool isBipartite(vector<vector<int>> &graph) {
        // Write your code here
        vector<int> color(graph.size(),-1);
        bool res = true;
        for(int i = 0; i < graph.size(); i++)
        {
            if(color[i] != -1) continue;
            dfs(graph,i,res,color,0);
        }
        
        return res;
    }
    
    void dfs(vector<vector<int>>& graph, int node, bool& res, vector<int>& color, int paint)
    {
        if(res == false) return;
        if(color[node] != -1)
        {
            if(color[node] != paint) res = false;
            return;
        }
        color[node] = paint;
        for(int i = 0; i < graph[node].size(); i++)
        {
            int next_node = graph[node][i];
            dfs(graph,next_node,res,color,1-paint);
        }
    }
};