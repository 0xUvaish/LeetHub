class Solution {
public:
    int countPairs(vector<int>& del)
    {
        vector<int>v(23,0);
        int p=1;
        
        for(int i=0;i<=22;i++)
        {
            v[i]=p;
            p=p*2;
        }
        
        int mod=1e9+7;
        int count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<del.size();i++)
        {
            for(auto it:v)
                if(mp.find(it-del[i])!=mp.end())
                    count=(count+mp[it-del[i]])%mod;
            
            mp[del[i]]++;
        }
    return count%mod;
    }
};