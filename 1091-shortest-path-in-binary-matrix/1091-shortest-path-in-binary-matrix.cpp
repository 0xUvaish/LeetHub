class Solution {
public:
 int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
          int n=grid.size();
        
          vector<vector<int>> dp(n,vector<int> (n,0));
          dp=grid;
          int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
          int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
          
          queue<pair<int,int>> q;
        
          if(grid[0][0]==1) 
              return -1;
     
          q.push({0,0});
          dp[0][0]=1;
     
        while(!q.empty())
        {

            pair<int,int> tp=q.front();
            q.pop();
             
            if(tp.first==n-1 and tp.second==n-1) 
                return dp[n-1][n-1];

            for(int i=0;i<8;i++)
            {

                int newx=tp.first  + dx[i];
                int newy=tp.second + dy[i];

                if(newx>=0 and newy>=0 and newx<n and newy<n)
                {
                   if(dp[newx][newy]==0)
                   {
                    q.push({newx,newy});
                    dp[newx][newy]=1 + dp[tp.first][tp.second];
                       
                    // if(newx==n-1 and newy==n-1) 
                    //     return dp[n-1][n-1];
                   }
                }
            }
    }
     return -1;
}
    
};