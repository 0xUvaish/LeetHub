class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        map<int,int> mp;
        for(auto t: tasks)
            mp[t]++;
    
        int ans=0;
        for(auto t: mp)
        {
            int k=t.second;
            if(k==1)
                return -1;
            if(k%3==0)
                ans+=k/3;
            else
                ans+=k/3+1;
        }
    
        return ans;
    }
};