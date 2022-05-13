class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2000,0));
        //dp[index][diff] equals to the length of arithmetic sequence at index with difference diff.
        int p=2;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int cd=nums[i]-nums[j]+1000;//to make cd always positive
                dp[i][cd]=max(2,dp[j][cd]+1);//since min length of an ap wll always be 2 
                 p=max(p,dp[i][cd]);//storing the max of all length
            }
        }
        return p;
    }
};