class Solution {
public:
void dfs(vector<int> adj[],vector<bool>& vis,int node,int& count)
{
    count++;
    vis[node]=true;
    for(auto i:adj[node])
    {
        if(!vis[i])
        dfs(adj,vis,i,count);
    }
}
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto v:edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<int> a;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int count=0;
                dfs(adj,vis,i,count);
                a.push_back(count);
            }
        }
        if(a.size()==1)
        return 0;
        int sum=0;
        for(auto it:a)
        sum+=it;
        long long ans=0,l=0;
        for(auto it:a)
        {
            l+=it;
            ans=ans+((sum-l)*it);
        }
        return ans;

    }
};