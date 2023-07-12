class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> ind(n,0);
        vector<int> adj[n];
        for(int i = 0;i < n;++i)
        {
            for(auto it : graph[i])
            {
                adj[it].push_back(i);
                ind[i] += 1;
            }
        }
        queue<int> q;
        vector<int> ans;
        for(int i = 0;i < n;++i)
        {
            if(ind[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(auto it : adj[node])
            {
                ind[it] -= 1;
                if(ind[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};