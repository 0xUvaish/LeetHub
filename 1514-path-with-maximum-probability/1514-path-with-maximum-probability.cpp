class Solution {
public:
   double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{

    vector<pair<double, int>> adj[n];
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        double pob = succProb[i];
        adj[u].push_back({pob, v});
        adj[v].push_back({pob, u});
    }

    priority_queue<pair<double, int>> pq;
    vector<double> distance(n, 0);
    distance[start] = 1.0;
     pq.push({1.0,start});

    while (!pq.empty())
    {
        double dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjnode = it.second;
            double wt = it.first;

            if (wt * dis > distance[adjnode])
            {
                pq.push({wt * dis, adjnode});
                distance[adjnode] = wt * dis;
            }
        }
    }

    return distance[end];
}
};