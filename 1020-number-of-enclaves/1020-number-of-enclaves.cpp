class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    void DFS(vector<vector<int>>& grid, int x,int y){
        grid[x][y] = 0;
        for(int i=0;i<4;i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx>=0 and xx<grid.size() and yy>=0 and yy<grid[0].size()){
                if(grid[xx][yy] == 1){
                    DFS(grid,xx,yy);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        // so we apply floodfill from the boundary of grid.
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i*j == 0 or i == rows-1 or j == cols-1){
                    if(grid[i][j] == 1){
                        DFS(grid,i,j);
                    }
                }
            }
        }
        int countisland = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    countisland++;
                }
            }
        }
        return countisland;
    }
};