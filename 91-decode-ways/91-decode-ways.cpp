class Solution {
public:
    int numDecodings(string s) 
    {
        int n = s.size();
        vector<int> dp(n+1);
        
        dp[0] = 1;
        dp[1] = (s[0]=='0' ? 0:1);
        
        for(int i=2;i<dp.size();i++)
        { 
            int onedigit = (s[i-1]-'0');
            int twodigit = 10*(s[i-2]-'0')+(s[i-1]-'0');
            
            if(onedigit>=1)
                dp[i] += dp[i-1];
            
            if(twodigit>=10 && twodigit<=26)
                dp[i] += dp[i-2]; //>=10 will take care of the leading zero case
        }
        
        return dp[dp.size()-1]; 
    }
};