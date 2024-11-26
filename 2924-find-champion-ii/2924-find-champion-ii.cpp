class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> in_degree(n, 0); // Track the number of incoming edges for each node.

        for (auto edge : edges) {
            int u = edge[0], v = edge[1];
            in_degree[v]++; // Increment in-degree for destination node.
        }

        int champion = 0; // To count nodes with zero in-degree.
        int ans = 0; // Store the node with zero in-degree.

        for (int i = 0; i < n; i++) {
            if (in_degree[i] == 0) { // Check for zero in-degree.
                champion++;
                ans = i;
            }
        }

        // If there's more than one champion, return -1.
        if (champion > 1)
            return -1;
        else
            return ans;
    }
};