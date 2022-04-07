class Solution {
public:
	 int dp[601][101][101];
    
    int fun(vector<string>& s, int m, int n , int l , int i)
    {
        if(i>=l || m<0 || n<0)
            return dp[i][m][n] = 0;
        
        if(m==0 && n==0)
            return dp[i][m][n]=0;
        
        if(dp[i][m][n]!=-1)
            return dp[i][m][n]; 
        
        int zero=0 , ones=0;
        for(int j=0;j<s[i].length();j++)
        {
            if(s[i][j] =='0')
                zero++;
            else
                ones++;
        }
        
       if(zero<=m && ones<=n) 
           return dp[i][m][n] = max(1+ fun(s,m-zero,n-ones,l,i+1), fun(s,m,n,l,i+1));
        else
            return dp[i][m][n] = fun(s,m,n,l,i+1);
        
    }
    
    int findMaxForm(vector<string>& s, int m, int n) 
    {
        int l = s.size();
        memset(dp , -1 , sizeof(dp));
        return fun(s, m,n,l,0);
        
    }
};