class Solution {
public:
     int numNodes = 0;
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
// build graph;
        vector<vector<int>> graph(n, vector<int>());
        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        numNodes = n;

        // dp
        vector<int> dp(n, 0);
        vector<int> sz(n, 0);

        vector<bool> visited(n, false);

        dfs_1(0, graph, visited, dp, sz);
        dfs_2(0, graph, visited, dp, sz);

        return dp;
    }
    
        int dfs_1(int u, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& dp, vector<int>& sz) {
        sz[u]++;
        visited[u] = true;
        for (auto v : graph[u]) {
            if (!visited[v]) {
                dp[u] += dfs_1(v, graph, visited, dp, sz) + sz[v];
                sz[u] += sz[v];
            }
        }
        return dp[u];
    }

    void dfs_2(int u, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& dp, vector<int>& sz) {
        visited[u] = false;
        for (auto v : graph[u]) {
            if (visited[v]) {
                dp[v] = dp[u] + numNodes - 2 * sz[v];
                dfs_2(v, graph, visited, dp, sz);
            }
        }
    }
};