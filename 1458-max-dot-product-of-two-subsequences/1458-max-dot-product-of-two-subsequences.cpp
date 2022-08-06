class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
        int special = INT32_MIN;
        
        for(int i=1; i<=n1; i++)
        {
            for(int j=1; j<=n2; j++)
            {
                dp[i][j] = max({dp[i-1][j-1] + nums1[i-1]*nums2[j-1], dp[i-1][j], dp[i][j-1]});
                special = max(special, nums1[i-1] * nums2[j-1]);
            }
        }
        
        if(dp[n1][n2] == 0) 
            return special;
        
        return dp[n1][n2];
    }
};