class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int m=s.size(),n=p.size();
        int lis=0,i=0;
        while(i<n)
        {
            if(p[i]=='*')
                i++;
            else
                break;
        }
        
        lis=i;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));
        for(int i=0;i<=n;i++)
            dp[0][i]=(i<=lis);
        
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j]=dp[i][j-1]||dp[i-1][j];
                else
                    dp[i][j]=(s[i-1]==p[j-1])&&dp[i-1][j-1];
            }
        }
        
        return dp[m][n];    
    }
};