class Solution {
    
    vector<vector<pair<int, int>>> G;
    public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n)
    {
        int N=n, M=maxMoves;
        G.resize(N);
        for(vector<int>& edge: edges)
        {
            int u = edge[0], v = edge[1];
            int c = edge[2];
            G[u].emplace_back(v, c);
            G[v].emplace_back(u, c);
        }
        
        vector<int> moves(N, -1);
        priority_queue<pair<int, int>> pq;
        pq.emplace(M, 0);
        int ans = 0;
        while(!pq.empty())
        {
            int mv = pq.top().first, now = pq.top().second;
            pq.pop();
            if(moves[now] >= 0) continue;
            moves[now] = mv;
            ans++;
            for(auto& [v, c]: G[now])
            {
                if(moves[v] >= 0) 
                    continue;
                if(mv - c - 1 < 0) 
                    continue;
                pq.emplace(mv - c - 1, v);
            }
        }
        
        for(vector<int>& edge: edges){
            int u = edge[0], v = edge[1];
            int c = edge[2];
            int left = moves[u] < 0 ? 0 : moves[u];
            int right = moves[v] < 0 ? 0 : moves[v];
            ans += min(left + right, c);
        }
        return ans;
    }
};