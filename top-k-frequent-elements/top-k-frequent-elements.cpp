class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        
        unordered_map<int,int>m;
        priority_queue<pair<int,int>>p;
        
        for(auto x:nums)
            m[x]++;
        
        for(auto t:m)
           p.push({t.second,t.first});
        
        nums.clear();
        while(k--)
        nums.push_back(p.top().second), p.pop();
        
    return nums;
    }
    
};