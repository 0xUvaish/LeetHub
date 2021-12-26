class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int n=points.size();
        priority_queue<pair<float,int>,vector<pair<float,int>>,greater<pair<float,int>>>pq;
        vector<vector<int>>res;
        
        int i=0;
        while(i<n)
        {
            float a=pow(points[i][0],2);
            float b=pow(points[i][1],2);
            float c=a+b;
            pq.push({sqrt(c),i});
            i++;
        }
        for(int c=0;c<k;c++)
        {
            int j=pq.top().second;
            pq.pop();
            res.push_back({points[j][0],points[j][1]});
        }
    return res;  
    }
};