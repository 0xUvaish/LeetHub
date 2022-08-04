class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<vector<int>> adj(n+1); //Manager to Subordinates
        for(int i=0;i<n;i++)
        {
            if(manager[i]!=-1)
                adj[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>> q;
        q.push({headID,informTime[headID]});
        
        int res=0;
        
        //Given graph is a tree structure (downwards)
        //BFS
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)  //Level Order
            {
                int u=q.front().first;
                int v=q.front().second;
                q.pop();
                
                if(adj[u].size()>0)
                {
                    for(auto x:adj[u])
                        q.push({x,v+informTime[x]});
                }
                else
                    res = max(res,v);
            }
        }
        
    return res;
    }
};