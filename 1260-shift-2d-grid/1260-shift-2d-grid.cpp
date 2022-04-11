class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
       vector<int> helper;
        int m = grid.size();
        int n = grid[0].size();
        int i=0;
        k %= (m*n);
        
        for(auto &x: grid)
            for(auto &y: x)
                helper.push_back(y);
        
        
        reverse(helper.begin()+m*n-k, helper.end());        
        reverse(helper.begin(), helper.begin()+m*n-k);
        reverse(helper.begin(), helper.end());
        
        for(auto &x: grid)
            for(auto &y: x)
                y = helper[i++];
        
        return grid;
    }
};