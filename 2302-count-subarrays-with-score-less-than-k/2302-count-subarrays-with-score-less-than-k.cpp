class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        long long sum=0;
        int i=0;
        int j=0;
        int n=nums.size();
        
        vector<long long> prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]+nums[i];
        
        long long csum;
        while(j<n)
        {
            csum=prefix[j]-(i>0 ? prefix[i-1] : 0);
            long long val=csum*(j-i+1);
            while(i<n && val>=k)
            {
                i++;
                csum=prefix[j]-prefix[i-1];
                val=csum*(j-i+1);
            }
            ans+=(j-i+1);         //Count subarrays line
            j++;
        }
        return ans;
    }
};