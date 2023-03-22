class Solution {
public:
    int find(int u, vector<int> &parents) {
        if (parents[u] == u)
            return u;

        return parents[u] = find(parents[u], parents);
    }

    void unionSets(int u, int v, int distance, vector<int> &parents, vector<int> &rank, vector<int> &score) {
        u = find(u, parents);
        v = find(v, parents);

        if (u == v) {
            score[u] = min(score[u], distance);
            return;
        }

        if (rank[u] < rank[v])
            swap(u, v);

        parents[v] = u;

        if (rank[u] == rank[v])
            rank[u]++;

        score[u] = min(score[u], min(score[v], distance));
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> parents(n + 1);
        vector<int> rank(n + 1, 0);
        vector<int> score(n + 1, INT_MAX);

        for (int i = 1; i <= n; i++)
            parents[i] = i;

        for (auto &road: roads) {
            int u = road[0];
            int v = road[1];
            int distance = road[2];

            unionSets(u, v, distance, parents, rank, score);
        }

        int parent = find(n, parents);
        return score[parent];
    }
};