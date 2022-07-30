class Solution {
public:
    //Multi Source BFS
    int maxDistance(vector<vector<int>>& grid) 
    {
        int mx = -1;
        int n = grid.size();
        vector<vector<int>>dis(n,vector<int>(n,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dis[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        
        int x[4] = {1,0,-1,0};
        int y[4] = {0,1,0,-1};
        
        while(!q.empty())
        {
            pair<int,int>p = q.front();
            q.pop();
            for(int dir=0;dir<4;dir++)
            {
                int nx = p.first+x[dir];
                int ny = p.second+y[dir];
                if(nx>=0 && nx<n && ny >=0 && ny <n && dis[nx][ny]==-1)
                {
                    dis[nx][ny] = dis[p.first][p.second]+1;
                    q.push({nx,ny});
                    
                    mx = max(mx,dis[nx][ny]);
                }
            }
        }
        return mx;
    }
};