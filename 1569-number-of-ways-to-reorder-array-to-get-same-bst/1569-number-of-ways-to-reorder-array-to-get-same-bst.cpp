class Solution {
    int mod= 1000000007;
public:
   int factorial(int n, int r, vector<vector<int>>& dp ){
        // code here
        if(n<=1 ||r==0 ||n==r)
        {
            return 1;
        }
        if(r==1)
        {
            return n ;
        }
        if(dp[n][r]!=-1)
        {
            return dp[n][r];
        }
        dp[n][r] = (factorial(n-1,r-1,dp)%mod + factorial(n-1,r,dp)%mod)%mod;
        return dp[n][r]%mod;
    }
    long long int ways( vector<int> & nums, vector<vector<int>>& dp)
    {
        if(nums.size()<=1)
        {
            return 1;
        }
        vector<int>left , right ;
        int root = nums[0];
        for( int i =1 ;i<nums.size() ;i++)
        {
            if(nums[i]<root)
            {
                left.push_back(nums[i]);
            }
            else
            {
                right.push_back(nums[i]);
            }
        }
        long long int ans = factorial(nums.size()-1 , left.size(), dp);
        long long int le = ways( left, dp);
        long long int ri = ways(right, dp);
        //cout<<le<<" "<<ri<<endl;
        ans*=((le%mod)*(ri%mod))%mod;
        ans%=mod;
        return ans%mod;
    }
    int numOfWays(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() , vector<int>(nums.size(),-1));
        return ways(nums ,dp)-1;
    }
};