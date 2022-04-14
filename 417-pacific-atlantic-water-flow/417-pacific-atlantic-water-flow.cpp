class Solution {

private:
        
    template<typename T>
    using Matrix = vector<vector<T>>;
    void dfs(Matrix<int>& heights, Matrix<bool>& visited, int i, int j, int prevHeight) {
        if (i < 0 || i >= heights.size() || j < 0 || j >= heights[0].size()
           || visited[i][j] || heights[i][j] < prevHeight) {
            return;
        }
        
        visited[i][j] = true;
        
        dfs(heights, visited, i + 1, j, heights[i][j]);
        dfs(heights, visited, i - 1, j, heights[i][j]);
        dfs(heights, visited, i, j + 1, heights[i][j]);
        dfs(heights, visited, i, j - 1, heights[i][j]);
    }
public:
    Matrix<int> pacificAtlantic(Matrix<int>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        Matrix<bool> pacific(m, vector<bool>(n, false));
        Matrix<bool> atlantic(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; ++i) {
            dfs(heights, pacific, i, 0, numeric_limits<int>::min());
            dfs(heights, atlantic, i, n - 1, numeric_limits<int>::min());
        }
        
        for (int j = 0; j < n; ++j) {
            dfs(heights, pacific, 0, j, numeric_limits<int>::min());
            dfs(heights, atlantic, m - 1, j, numeric_limits<int>::min());
        }
        
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j)
                if (pacific[i][j] && atlantic[i][j]) 
                    result.push_back({i, j});
        
        return result;
    }

};