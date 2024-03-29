class Solution {
public:
    int maxsum(vector<int>&arr,int idx,vector<int>&dp,int k)
    {
        if(idx==arr.size())
            return 0;
        
        if(dp[idx]!=0)
            return dp[idx];
        
            int res=-1,ans=0;
            for(int i=idx;i<arr.size() && i<idx+k; i++)
            {
                res=max(res,arr[i]);
                ans=max(ans,res*(i-idx+1)+maxsum(arr,i+1,dp,k));
            }
        
            return dp[idx]=ans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k)
    {
        int n=arr.size();
        vector<int> dp(n,0);
        int sum=maxsum(arr,0,dp,k);
        return sum;
		
    }
};