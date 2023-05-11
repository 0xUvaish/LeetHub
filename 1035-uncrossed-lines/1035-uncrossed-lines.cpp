class Solution {
public:
    vector<vector<int>> dp;
    int lcs(vector<int>& nums1, vector<int>& nums2, int i, int j)
    {
        if(i == 0 || j == 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(nums1[i-1] == nums2[j-1])
            return  dp[i][j] = 1 + lcs(nums1,nums2,i-1,j-1);
        return dp[i][j] = max(lcs(nums1,nums2,i-1,j),lcs(nums1,nums2,i,j-1));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        dp.resize(nums1.size()+1,vector<int>(nums2.size()+1,-1));
        return lcs(nums1,nums2,nums1.size(),nums2.size());
    }
};