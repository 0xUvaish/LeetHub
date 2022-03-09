class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={-1,1,0,0};
    void dfs(vector<vector<int>>& grid,int x,int y,int r,int c)
    {    
        grid[x][y]=-1;  
         for(int i=0;i<4;i++)
           {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(newx>=0 && newy>=0 && newx<r && newy<c && grid[newx][newy]==0)
               dfs(grid,newx,newy,r,c);
            }
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
    
	 
        for(int i=0;i<r;i++) 
          {
            
             if(grid[i][0]==0) dfs(grid,i,0,r,c);
             if(grid[i][c-1]==0) dfs(grid,i,c-1,r,c);
          }
        
        for(int j=0;j<c;j++)
          {
              if(grid[0][j]==0) dfs(grid,0,j,r,c);
              if(grid[r-1][j]==0) dfs(grid,r-1,j,r,c);
          }
     
       int count=0;
        for(int i=0;i<r;i++)
        {
          for(int j=0;j<c;j++)
            {
            if(grid[i][j]==0)
                {
                    count++;
                    dfs(grid,i,j,r,c);
                 }
             }
        }
        
        return count; 
    }
};