class Solution {
public:
    
    bool isSafe(int i, int j, int m, int n)
    {
        if(i>=0 && i<m && j>=0 && j<n)
            return true;
    return false;
    }
        
    void dfs(int i, int j, int m, int n, vector<vector<char>>& grid)
    {
        if(!isSafe(i,j,m,n) || grid[i][j]!='1')
            return;
        

        grid[i][j]='0';
        
        dfs(i-1,j,m,n,grid);
        dfs(i+1,j,m,n,grid);
        dfs(i,j+1,m,n,grid);
        dfs(i,j-1,m,n,grid);
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
       int m=grid.size();
       int n=grid[0].size();
        int c=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    c++;
                    dfs(i,j,m,n,grid);
                }
                    
            }
        }
        
    return c;
    }
};