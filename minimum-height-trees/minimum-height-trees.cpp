class Solution {
public:
    vector<int>dp[20009];
    void find(int x,vector<int>&curr,vector<int>&path,vector<bool>&vis)
    {
        vis[x]=true;
        curr.push_back(x);
        if(curr.size()>path.size())
            path=curr;
        
        for(auto it:dp[x])
            if(vis[it]==false)
                find(it,curr,path,vis);
        
        curr.pop_back();
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& nums)
    {
        for(auto it:nums)
        {
            int x=it[0];
            int y=it[1];
            dp[x].push_back(y);
            dp[y].push_back(x);
        }
        vector<bool>vis(n+1,false);
        vector<int>curr,path;
        find(0,curr,path,vis);
        int node=path.back();
        path.resize(0);
        for(int i=0;i<n+1;i++)
            vis[i]=false;
        
        find(node,curr,path,vis);
            int size=path.size();
            if(size&1)
                return {path[size/2]};
        
        return {path[size/2],path[size/2-1]};
    }
};