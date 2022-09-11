class Solution {
public:
#define ll long long int
    static bool compt(vector<int>& a, vector<int>& b)
    {
        return a[1] < b[1];
    }
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) 
    {
        vector<vector<int>> v;
        for(int i=0;i<n;i++) v.push_back({speed[i], efficiency[i]});
        sort(v.begin(), v.end(), compt);
        priority_queue<int, vector<int>, greater<int>> pq;
        ll res = 0, currsum = 0;
        int tobe = k-1;
        for(int i=n-1;i>=0;i--) 
        {
            currsum += v[i][0];
            if(pq.size() > tobe)
            {
                currsum -= pq.top(), pq.pop();
            }
            pq.push(v[i][0]);
            res = max(res, currsum*v[i][1]);
        }
        int val = 1e9 + 7;
        return (int)(res%val);
        
    }
};