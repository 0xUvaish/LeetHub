class Solution {
public:
    //Method 1: Recursion/Top Down Dp
    int help(string &s, vector<int> &dp, int index)
    {
        if(index==0)
            return s[0]>'0';
        else if(index==-1)
            return 1;
        
        if(dp[index]!=-1)
            return dp[index];
        
        int count=0;
        
        int oneDigit = s[index]-'0';
        int twoDigit = (index>0 ? 10*(s[index-1]-'0')+(s[index]-'0'): 0);
        
        if(oneDigit>=1)
            count = help(s,dp,index-1);
        if(twoDigit>=10 && twoDigit<=26)
            count += help(s,dp,index-2);
        
        return dp[index]=count;
        
    }
    
    int numDecodings(string s) 
    {
        int n = s.size();
        if(n==1)
            return s[0]>'0';
            
        vector<int> dp(n,-1);
        return help(s,dp,n-1);
    }    
    
    //Method 2: O(n) & O(n)
    //Bottom Up Approach - DP
//     int numDecodings(string s) 
//     {
//         int n = s.size();
//         vector<int> dp(n+1,0);
        
//         //dp[i] means no. of ways to decode i length string from starting
        
//         dp[0] = 1;
//         dp[1] = (s[0]=='0' ? 0:1);
        
//         for(int i=2;i<=n;i++)
//         { 
//             int onedigit = (s[i-1]-'0');
//             int twodigit = 10*(s[i-2]-'0')+(s[i-1]-'0');
            
//             if(onedigit>=1)
//                 dp[i] = dp[i-1];
            
//             if(twodigit>=10 && twodigit<=26)
//                 dp[i] += dp[i-2]; //>=10 will take care of the leading zero case
//         }
        
//         return dp[n]; 
//     }
};