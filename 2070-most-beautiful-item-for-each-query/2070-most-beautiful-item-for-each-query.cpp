class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        map<int ,int>mp;
        vector<int> res;
        
        sort(items.begin(), items.end());
        
        int maxbeauty=INT_MIN;
        for(auto i:items)
        {
            maxbeauty=max(maxbeauty,i[1]);
            mp[i[0]]=maxbeauty;
        }
        
        
        
        int ans;
        for(int z=0;z<queries.size();z++)
             { 
                if(mp.find(queries[z])!=mp.end())
                    ans=mp[queries[z]];
                 else
                 {
                     auto it = mp.lower_bound(queries[z]);
                     if(it!=mp.begin())
                     {
                         it--;
                         ans=(*it).second;
                     }
                     else
                         ans=0;
                 }
            
            res.push_back(ans);
             }
        
    return res;
    }
};