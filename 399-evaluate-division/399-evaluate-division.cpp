class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> mp;
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        for(int i=0;i<equations.size();i++)
        {
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        
        vector<double> ans;
        for(auto q: queries)
        {
            string p1 = q[0];
            string p2 = q[1];
            
            if(mp.find(p1) == mp.end() && mp.find(p2) == mp.end())
            {
                ans.push_back(-1.00);
                continue;
            }
            
            unordered_map<string, bool> vis;
            ans.push_back(dfs(p1, p2, vis));
        }
        return ans;
    }
    
    double dfs(string x, string y, unordered_map<string, bool> &vis)
    {
        if(x == y)
            return 1.00;
        
        vis[x] = true;
        
        for(int i=0;i<mp[x].size();i++)
        {
            if(!vis[mp[x][i].first])
            {
                double ans = mp[x][i].second * dfs(mp[x][i].first, y, vis);
                if(ans > 0.0)
                    return ans;
            }
        }
        return -1.00;
    }
};