class Solution {
public:
    vector<vector<int>> dirs = {{-1,0},{0,-1},{1,0},{0,1}};
    
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j){        
        if(grid2[i][j]==1 && grid1[i][j]==0)
            return false;
        
        grid2[i][j] = 0;
        bool val = true;

        for(auto it : dirs)
        {
        int x = it[0] + i;
        int y = it[1] + j;
            
        if(x<0 || x>=grid2.size() || y<0 || y>=grid2[0].size() || grid2[x][y]==0)
            continue;
            
        val = val & dfs(grid1, grid2, x, y); 
        }
        
        return val;
    }
	
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int ans = 0;
        for(int i=0; i<grid2.size(); i++)
            for(int j=0; j<grid2[i].size(); j++)
                if(grid2[i][j]==1)
                    ans += dfs(grid1, grid2, i, j);
        
        return ans; 
    }
};