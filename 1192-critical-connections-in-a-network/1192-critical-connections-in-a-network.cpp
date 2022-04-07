class Solution {
public:
    vector<vector<int>> ans;
    void addEdge(vector<int> adj[],vector<vector<int>>& connections)
    {
        for(int i=0; i<connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
    }
    // Bridges Algo is here
    void dfs(vector<int> adj[],int disc[],int low[],bool visited[],int s,int parent,int &time)
    {
        visited[s] = true;
        disc[s] = low[s] = ++time;
        
        for(int &v: adj[s]){
            if(!visited[v]){
                dfs(adj,disc,low,visited,v,s,time);
                low[s] = min(low[s],low[v]);
                if(low[v] > disc[s])
                    ans.push_back({s,v});
            }
            else if(v != parent)
                low[s] = min(low[s],disc[v]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        vector<int> adj[n];
        addEdge(adj,connections);
        int tin[n];
        fill(tin,tin+n,0);
        int low[n];
        fill(low,low+n,0);
        bool visited[n];
        fill(visited,visited+n,false);
        int time = 0;
        dfs(adj,tin,low,visited,0,-1,time);
        return ans;
    }
};