class Solution {
public:
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool dfs(int x, int y, vector<vector<int>> &heights, int limit, vector<vector<bool>> &vis)
    {
    if (x < 0 || y < 0 || x >= heights.size() || y >= heights[0].size() || vis[x][y] == true ||heights[x][y] > limit)
            return false;
        
        vis[x][y] = true;
        
        if(x == heights.size()-1 && y==heights[0].size()-1)
            return true;
        
        for (int i = 0; i < 4; i++)
            if(dfs(x + dir[i][0], y + dir[i][1], heights, limit, vis))
                return true;
        
        return false;
    }
    
    int swimInWater(vector<vector<int>> &heights)
    {
            int left = 0, right = 2500, ans = 0, mid;
            while (left <= right)
            {
                mid = left + (right - left) / 2;
                vector<vector<bool>> vis(heights.size(), vector<bool>(heights[0].size(), false));
				if (dfs(0, 0, heights, mid, vis))
                {
                    ans = mid;
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
            return ans;
    }
};