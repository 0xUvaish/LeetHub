class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int h = triangle.size() - 1;
        while(h != 0)
        {
            for(int i = 0; i < h; ++i)
                triangle[h - 1][i] += min(triangle[h][i], triangle[h][i + 1]);
            h--;
        }
        
    return triangle[0][0];  
    }
};