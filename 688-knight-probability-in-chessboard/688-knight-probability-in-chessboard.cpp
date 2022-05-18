class Solution {
public:
    double dp[26][26][101];
    int dirs[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
 
    double dfs(int n,int k,int r, int c)
    {
        if(r<0||r>=n||c<0||c>=n)
            return 0.0;
        
        if(k==0)
            return 1.0;
        
        if(dp[r][c][k]>0.0)
            return dp[r][c][k];
        
        double probability=0.0;
        for(int i=0;i<8;i++)
            probability+=dfs(n,k-1,r+dirs[i][0],c+dirs[i][1])/8.0;
        
        return dp[r][c][k]=probability;
    }
    
    
    double knightProbability(int n, int k, int row, int column) 
    {
        return dfs(n,k,row,column);
    }
};