class Solution {
public:
    
    void dfs(vector<int> adj[],vector<int> &vis,int node)
    {
        vis[node]=1;
        for(auto x: adj[node])
            if(!vis[x])
                dfs(adj,vis,x);
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n=rooms.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++)
            for(int j=0;j<rooms[i].size();j++)
                adj[i].push_back(rooms[i][j]);
        
        vector<int> vis(n,0);
        
        int cmp=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                cmp+=1;
                dfs(adj,vis,i);
            }
        }
        
    return cmp==1;
    }
};