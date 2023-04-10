class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        
        vector<vector<int>> count(colors.length(), vector<int>(26, 0));
        int res = 0;
        unordered_set<int> visit, path;
        for (int i = 0; i < colors.length(); i++) {
            res = max(res, dfs(i, adj, colors, count, visit, path));
        }
        
        return (res == INT_MAX) ? -1 : res;
    }
    
    int dfs(int node, unordered_map<int, vector<int>>& adj, string& colors, vector<vector<int>>& count, unordered_set<int>& visit, unordered_set<int>& path) {
        if (path.find(node) != path.end()) {
            return INT_MAX;
        }
        if (visit.find(node) != visit.end()) {
            return 0;
        }
        
        visit.insert(node);
        path.insert(node);
        int color_idx = colors[node] - 'a';
        count[node][color_idx] = 1;
        
        for (auto& nei : adj[node]) {
            int sub_res = dfs(nei, adj, colors, count, visit, path);
            if (sub_res == INT_MAX) {
                return INT_MAX;
            }
            for (int i = 0; i < 26; i++) {
                count[node][i] = max(count[node][i], (i == color_idx ? 1 : 0) + count[nei][i]);
            }
        }
        
        path.erase(node);
        return *max_element(count[node].begin(), count[node].end());
    }
};