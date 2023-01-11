class Solution {
public:
    
    // dfs function
    
    int dfs(vector<vector<int>>& adj, int u, vector<bool>& vis, vector<bool>& has)
    {
        // mark the curr node visited
        
        vis[u] = true;
        
        // base case, if the curr node is leaf node and has apple return 1
        
        if(adj[u].size() == 1 && vis[adj[u][0]])
        {
            if(has[u])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        // find total time after calling to all the adjacent nodes
        
        int time = 0;
        
        for(auto v : adj[u])
        {
            if(vis[v] == false)
            {
                time += dfs(adj, v, vis, has);
            }
        }
        
        // return the time according to condition
        
        if(time == 0 && has[u])
        {
            return 1;
        }
        else if(time != 0)
        {
            return 1 + time;
        }
        
        return 0;
    }
    
    int minTime(int V, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        // make adjacency list
        
        vector<vector<int>> adj(V);
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            
            int v = edges[i][1];
            
            adj[u].push_back(v);
            
            adj[v].push_back(u);
        }
        
        // declare a visited array
        
        vector<bool> vis(V, false);
        
        // call dfs and find time
        
        int time = dfs(adj, 0, vis, hasApple);
        
        if(time == 0)
            return 0;
        
        time--;
        
        return 2 * time;
    }
};
