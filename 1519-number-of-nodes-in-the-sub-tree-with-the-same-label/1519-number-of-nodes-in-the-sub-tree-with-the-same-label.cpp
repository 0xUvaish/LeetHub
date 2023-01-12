class Solution {
public:
    vector<int>adj[100001];
    int vis[100001]={0};
    void dfs(int node,string &l,vector<int>&ans,vector<int>&v){
            if(vis[node]==1)return;
            vis[node]=1;
            for(auto it:adj[node]){
                if(!vis[it]){
                vector<int>a(26,0);
                    dfs(it,l,a,v);
                    for(int i=0;i<26;i++){
                        ans[i]+=a[i];
                    }
                }

            }
            ans[l[node]-'a']++;
            v[node]=ans[l[node]-'a'];
            return;
            
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for(auto it:edges){
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }
        vector<int>ans(26,0);
        vector<int>v(n,0);
        dfs(0,labels,ans,v);
        return v;

        
    }
};