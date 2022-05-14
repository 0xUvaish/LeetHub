class Solution {
    vector<vector<vector<int>>>memo;
    long long int mod=1e9+7;
    
    int help(int n,int i,int j)
    {
        if(i<0 || j<0 || i>3 || j>2 || (i==3 && j==2) || (i==3 && j==0))
            return 0;
        
        if(n==0)
            return 1;
        
        if(memo[i][j][n]!=-1)
            return memo[i][j][n];
        
        int ans=0;
        ans=(ans%mod+help(n-1,i-2,j-1)%mod)%mod;
        ans=(ans%mod+help(n-1,i-2,j+1)%mod)%mod;
        ans=(ans%mod+help(n-1,i-1,j-2)%mod)%mod;
        ans=(ans%mod+help(n-1,i+1,j-2)%mod)%mod;
        ans=(ans%mod+help(n-1,i+2,j-1)%mod)%mod;
        ans=(ans%mod+help(n-1,i+2,j+1)%mod)%mod;
        ans=(ans%mod+help(n-1,i-1,j+2)%mod)%mod;
        ans=(ans%mod+help(n-1,i+1,j+2)%mod)%mod;
        
        return memo[i][j][n]=ans%mod;
   
    }
public:
    int knightDialer(int n) 
    {
        memo=vector<vector<vector<int>>>(4,vector<vector<int>>(3,vector<int>(n,-1)));
        long long int ans=0;
        
        for(int i=0;i<=3;i++)
            for(int j=0;j<=2;j++)
                ans+=help(n-1,i,j)%mod;
        
        return ans%mod;
    }
};