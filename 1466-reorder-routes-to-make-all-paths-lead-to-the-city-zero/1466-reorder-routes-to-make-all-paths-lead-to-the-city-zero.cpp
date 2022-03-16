class Solution {
    
  public:
    
    int minChanges(int src, vector<int> adj[], vector<int> revAdj[], int p)
    {
        int changes = 0;
        for(int child: adj[src])
        {
            if(child != p)
                changes += minChanges(child, adj, revAdj, src) + 1; // only diff (forward edge)
        }
        
        for(int child: revAdj[src]) 
        {
            if(child != p)
                changes += minChanges(child, adj, revAdj, src);
        }
        
        return changes;
    }
    
    
    int minReorder(int n, vector<vector<int>> &connections) 
    {
        vector<int> adj[n], revAdj[n];
        int e = connections.size();
        
        for(int i = 0; i < e; i++) 
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            revAdj[connections[i][1]].push_back(connections[i][0]);  
        }
        
        return minChanges(0, adj, revAdj, -1);
    }
    
};