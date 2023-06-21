class Solution {
public:
    long long  left,right,a1,a2,mid,ans=LLONG_MAX;
    long long huy(vector<int>& nums, vector<int>& cost, long long k)
    {
        long long sum=0;
        for(int i=0;i<=nums.size()-1;i++)
        {
            sum=sum+abs(k-nums[i])*cost[i];
        }
        return sum;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ma=INT_MIN,mi=INT_MAX,dem=0;
        for(int i=0;i<=nums.size()-1;i++)
        {
           if(nums[i]==nums[0]) dem++;
           if(nums[i]>ma) ma=nums[i];
           if(nums[i]<mi) mi=nums[i];
        }
        if(dem==nums.size()) return 0;
        left=mi;
        right=ma;
        while(left<right)
        {
            mid=(left+right)/2;
            a1=huy(nums,cost,mid);
            a2=huy(nums,cost,mid+1);
            ans=min(ans,min(a1,a2));
            if(a1>a2)
            {
                left=mid+1;
            }
            if(a2>a1)
            {
                right=mid;
            }
            if(a2==a1)
            {
                return ans;
            }
        }
        return ans;
    }
};