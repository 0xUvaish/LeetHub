class Solution {
public:
    bool dfs(int row, int col, int limit, int prev,
             vector<vector<int>>& heights, vector<vector<bool>>& visited) 
    {
        if(row < 0 || row >= heights.size() || col < 0 || col >= heights[0].size()
          || visited[row][col] || abs(heights[row][col] - prev) > limit)
            return false;
        
        visited[row][col] = true;

        if(row == heights.size()-1 && col == heights[0].size()-1)
            return true;
        
        return dfs(row, col+1, limit, heights[row][col], heights, visited)
            || dfs(row, col-1, limit, heights[row][col], heights, visited)
            || dfs(row+1, col, limit, heights[row][col], heights, visited)
            || dfs(row-1, col, limit, heights[row][col], heights, visited);
    }

    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        const int M = heights.size(), N = heights[0].size();
        
        int upper = INT_MAX, lower = 0;
        int ans=0;
        
        while(lower <= upper) 
        {
            vector<vector<bool>> visited(M, vector<bool>(N, false));
            
            int mid = lower + (upper - lower) / 2;
            if(dfs(0, 0, mid, heights[0][0], heights, visited))
            {
                ans = mid;
                upper = mid-1;
            }
            else
                lower = mid + 1;
        }
        return ans;
    }
};