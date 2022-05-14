class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int n = points.size();
        int ans = INT_MIN;
        
        priority_queue<pair<int, int>> pq;
        
        for(int j=0; j<n; j++)
        {
            
            while((!pq.empty()) && points[j][0]-pq.top().second>k)
                pq.pop();
                
            if(!pq.empty())
                ans = max(ans, (pq.top().first + points[j][0] + points[j][1]));
            
            pq.push({points[j][1] - points[j][0], points[j][0]});
        }
        
        return ans;
    }
};