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
    void dfs(vector<int> adj[],vector<int> &tin,vector<int> &low,vector<bool> &visited,int s,int parent,int &time)
    {
        visited[s] = true;
        tin[s] = low[s] = ++time;
        
        for(int &v: adj[s])
        {
            if(!visited[v])
            {
                dfs(adj,tin,low,visited,v,s,time);
                low[s] = min(low[s],low[v]);
                if(low[v] > tin[s])             //If its a bridge
                    ans.push_back({s,v});
            }
            else if(v != parent)
                low[s] = min(low[s],tin[v]);
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections)
    {
        vector<int> adj[n], tin(n,-1), low(n,-1);
        vector<bool> visited(n, false);
        
        addEdge(adj,connections);  //Created the graph
        int time = 0;
       
        //Following lines in case of multiple components in the graph
        /*
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(adj,tin,low,visited,i,-1,time);               
            }
        }
        */
        
        //Here all are already connected so just one component, hence can start from any node (0 in this case)
        dfs(adj,tin,low,visited,0,-1,time);  //Run Tarjan's Algo
        
        return ans;
    }
};