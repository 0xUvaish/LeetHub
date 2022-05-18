class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int &count)
    {
        vis[node] = 1;
        count++;
        
        for(auto nd:adj[node])
            if(!vis[nd])
                dfs(nd, adj, vis, count);  
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {   
                if(i == j) 
                    continue;
                
                long long x2 = max(bombs[j][0], bombs[i][0]);
                long long x1 = min(bombs[j][0], bombs[i][0]);
                long long y2 = max(bombs[j][1], bombs[i][1]);
                long long y1 = min(bombs[j][1], bombs[i][1]);
                
                long long dist = ceil(sqrt(((x2 - x1)*(x2-x1)) + ((y2 - y1)*(y2-y1))));
                long long range = bombs[i][2];
                
                if(dist <= range)
                    adj[i].push_back(j);
            }
        }
        

        int maxCount = INT_MIN;
        for(int i=0; i<n; i++)
        {   
            vector<int> vis(n);
            int count = 0;
            
            dfs(i, adj, vis, count);
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};