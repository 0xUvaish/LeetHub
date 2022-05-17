class Solution {
public:
    int dp[501][501];
    int func(vector<int>& prefixSum, int l, int r)
    {
        if(r-l+1 == 1)
            return 0;
        
        if(dp[l][r]!=-1)
            return dp[l][r];
        
        int res=0;
        for(int i=l;i<r;i++)
        {
            int left_sum=prefixSum[i+1]-prefixSum[l];
            int right_sum=prefixSum[r+1]-prefixSum[i+1];
            
            if(left_sum<right_sum)
                res=max(left_sum+func(prefixSum,l,i),res);
            
            else if(left_sum>right_sum)
                res=max(right_sum+func(prefixSum,i+1,r),res);
            
            else
                res=max({res,left_sum+func(prefixSum,l,i),right_sum+func(prefixSum,i+1,r)});         
        }
        return dp[l][r] = res;
    }
    
    int stoneGameV(vector<int>& stoneValue) 
    {
        int n=stoneValue.size();
        vector<int> prefixSum(n+1,0);
        
        for(int i=1;i<n+1;i++)
            prefixSum[i]=prefixSum[i-1]+stoneValue[i-1];
        
        memset(dp,-1,sizeof(dp));
        return func(prefixSum,0,n-1);
    }
};