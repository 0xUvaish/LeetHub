class Solution {
public:
    int getArea(vector<vector<int>>& grid, int i, int j, int m, int n){
        
        grid[i][j] = -1;
        int area = 1;
        
        if((j-1)>=0 && (j-1)<n && grid[i][j-1] == 1)
            area += getArea(grid, i, j-1, m, n);
        if((i-1)>=0 && (i-1)<m && grid[i-1][j] == 1)
            area += getArea(grid, i-1, j, m, n);
        if((j+1)>=0 && (j+1)<n && grid[i][j+1] == 1)
            area += getArea(grid, i, j+1, m, n);
        if((i+1)>=0 && (i+1)<m && grid[i+1][j] == 1)
            area += getArea(grid, i+1, j, m, n);
        
    return area;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    int area = getArea(grid, i, j, m, n);
                    maxArea = (maxArea<area)?area:maxArea;
                }
            }
        }
        return maxArea;
        
    }
};