class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        int maxl=0, currlen=0, start;
        for(auto x: nums)
            mp[x]=true;
        
        for(auto y: mp)
            if(mp.find(y.first-1)!=mp.end())
                mp[y.first]=false;
        
        for(auto z: mp)
        {
            if(z.second==true)
            {
                currlen=1;
                start = z.first;
                while(mp.find(start+1)!=mp.end())
                {
                    currlen++;
                    start++;
                }
            
             maxl = max(maxl, currlen);
                
            }
        }
        
return maxl;
        
    }
};