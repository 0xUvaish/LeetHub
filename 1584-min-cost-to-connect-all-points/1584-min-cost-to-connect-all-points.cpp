class Solution {
public:
    
    //Prims Algorithms using Priorirty Queue - PepCoding Method
    int minCostConnectPoints(vector<vector<int>>& points) {
          
        int n = points.size();
        vector<vector<int>> graph(n, vector<int>(n)); //Adjacency Matrix
        
        
        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<n; j++)
            {
                if(i==j)                //As distance will be zero anyways
                    continue;
                graph[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        } 
        

        vector<int> visited(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        //Weight of edge, Node reachable using that edge
        pq.push({0,0});
        int ans=0;
      
        while(!pq.empty())
        {
            auto best=pq.top();
            pq.pop();
            
            int node=best.second;
            int weight=best.first;
            
            if(visited[node])
                continue;
            
            visited[node]=1;   
            ans+=weight;
            
            for(int i=0;i<n;i++)
                if(!visited[i])
                    pq.push({graph[node][i],i});
            
        }
        
return ans;
    }
};