class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        
        unordered_map<int,int>m;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        for(auto x:nums)
            m[x]++;
        
        for(auto t:m)
        {
            pq.push({t.second,t.first});
            if(pq.size()>k)
                pq.pop();
        }
        
        nums.clear();
        while(pq.size())
        nums.push_back(pq.top().second), pq.pop();
        
    return nums;
    }
    
};