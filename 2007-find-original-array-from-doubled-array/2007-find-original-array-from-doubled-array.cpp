class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
        vector<int> ans;
        if(n%2!=0)
            return ans;
        
        sort(changed.begin(), changed.end());
        unordered_map<int, int> mp;
        
        for(auto x: changed)
            mp[x]++;
        
        
        for(int i=n-1;i>=0;i--)
        {
            if(changed[i]%2==0 && (changed[i]!=0 && changed[i]!=1))
            {
                if(mp[changed[i]/2] && mp[changed[i]])
                {
                    ans.push_back(changed[i]/2);
                    mp[changed[i]]--;
                    mp[changed[i]/2]--;
                }
            }
        }
       for(auto x:mp)
       {
           if(x.first==0 && x.second%2==0)
               while(x.second>0)
               {ans.push_back(x.first);
                    x.second-=2;
               }
       }
        
    if(ans.size()==n/2)
        return ans;
    else
    {
        ans.clear();
        return ans;
    }
}
};