class Solution {
public:
int min(int a,int b,int c)
    {
        int x=INT_MAX;
        if(a<x)
            x=a;
        if(b<x)
            x=b;
        if(c<x)
            x=c;
        return x;
    }
    
    int minDistance(string word1, string word2) 
    {
        int l1=word1.length(),l2=word2.length();
        int dp[l1+1][l2+1];
        
        for (int i=0;i<=l1;i++)
        {
            for (int j=0;j<=l2;j++)
            {
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=min(dp[i-1][j-1],dp[i][j-1],dp[i-1][j])+1;
            }
        }
        return dp[l1][l2];
    }
};