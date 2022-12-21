class Solution {
public:
// 2-Color Problem - DFS
 bool isPossibleTwoclr(vector<int> adj[], int src, vector<int> &clr, int c)
 {
        clr[src]=c;
        for(auto &x:adj[src])
        {
            if(clr[x]==-1)
            {
                if(!isPossibleTwoclr(adj,x,clr,1-c))
                    return false;
            }
            else
            {
                if(clr[x]==c)
                    return false;
            }
        }

        return true;        
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dis) 
    {
        vector<int> adj[n];
        vector<int> clr(n,-1);
        
        for(auto &x:dis)
        {
            adj[x[0]-1].push_back(x[1]-1);
            adj[x[1]-1].push_back(x[0]-1);
        }
        
        for(int i=0;i<n;i++)
            if(clr[i]==-1)
                if(!isPossibleTwoclr(adj,i,clr,0))
                    return false;
    
        return true;
    }
};