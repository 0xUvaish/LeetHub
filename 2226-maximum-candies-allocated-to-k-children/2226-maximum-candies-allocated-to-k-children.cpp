class Solution {
public:
    #define ll long long
    bool help(vector<int>& candies,ll k,ll each)
    {
        ll c=0;
        if(each==0)
            return 1;
        
        for(int i=0;i<candies.size();i++)
            c+=candies[i]/each;
        
        return c>=k;
    }

    
    int maximumCandies(vector<int>& candies, long long k) {
        
        ll low=0, ans=0;
        ll high=*max_element(candies.begin(),candies.end());;
        
        while(low<=high)
        {
            ll mid=(low+high)/2;
            
            if(help(candies,k,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return ans;
    }
};