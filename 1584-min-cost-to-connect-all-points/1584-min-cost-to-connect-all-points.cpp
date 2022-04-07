class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
          
        int n = points.size();
        vector<vector<int>> graph(n, vector<int>(n));
        
        for(int i=0; i<n; i++) 
            for(int j=0; j<n; j++)
                graph[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        

        vector<int>visited;
        visited.assign(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,0});
        int ans=0;
      
        while(!pq.empty())
        {
    
            auto best=pq.top();
            pq.pop();
            
            int src=best.second;
            int weight=best.first;
            
            if(visited[src])
                continue;
            
            visited[src]=1;   
            ans+=weight;
            
            for(int i=0;i<n;i++)
                if(visited[i]==0)
                    pq.push(make_pair(graph[src][i],i));
            
        }
        
return ans;
    }
};