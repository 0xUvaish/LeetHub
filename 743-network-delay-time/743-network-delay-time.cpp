class Solution {
public:
    //Dijkstra's
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        
        int answer = 0 , count = 0;
        vector<pair<int,int>>adj[101];
        
        for(auto it : times)
            adj[it[0]].push_back({it[1],it[2]});
               
        unordered_set<int>st;
        priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> >> pq;
        int dist[101];
        
        for(int i=0;i<=n;++i)
            dist[i] = INT_MAX;
        
        dist[k] = 0;
        pq.push({0,k});
        
        while(!pq.empty())
        {
            auto top = pq.top();
            st.insert(top.second);
            pq.pop();
            
            for(auto it : adj[top.second])
            { 
                if(st.find(it.first) != st.end())
                    continue;
                if(dist[it.first] > dist[top.second]+it.second)
                {
                    dist[it.first] = dist[top.second] + it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        
        for(int i=1;i<=n;++i)
            answer = max(answer,dist[i]);
        
        return (st.size() == n) ? answer : -1;
    }
};