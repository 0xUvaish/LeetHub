class Solution {
public:
    int minSetSize(vector<int>& arr) {
       unordered_map<int, int> mp;
        int n = arr.size();
        for(auto x: arr)
            mp[x]++;

        
        priority_queue<pair<int, int>> pq;
        for(auto z: mp)
            pq.push({z.second, z.first});
        
        int cnt=0, freq=n;
        while(!pq.empty() && freq>n/2)
        {
          cnt++;
          freq -= pq.top().first;
          pq.pop();
        }
        
        return cnt;
    }
};