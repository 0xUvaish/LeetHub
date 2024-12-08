class Solution {
public:
int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int maxVal = 0;
        
        priority_queue<vector<int>> pq;
        int ans = 0;
        
        for(auto e : events){
            while(!pq.empty() and ((-pq.top()[0]) < e[0])){
                maxVal = max(maxVal , pq.top()[2]);
                pq.pop();
            }
            ans = max(ans , e[2]+maxVal);
            pq.push({(-e[1]) , e[0] , e[2]});
        }
        return ans;
    }
};