class Solution {
public:
    bool dfs(int node,vector<int> adj[],vector<int>& vis,int destination)
    {
        if(node==destination)
            return 1;
    
        vis[node]=1;
        for(auto it: adj[node])
            if(!vis[it])
                if(dfs(it,adj,vis,destination))
                    return 1;
        
        return 0;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination)
    {
        vector<int> adj[n];
    
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    
        vector<int> vis(n,0);
    
        return dfs(source,adj,vis,destination); 
    }
};