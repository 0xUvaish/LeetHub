class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int lx = 0, rx = matrix.size();
        int midx = (lx + rx) / 2;
        
        while (lx < rx)
          {
            if(matrix[midx].back() >= target && matrix[midx][0] <= target)
            {
                int ly = 0, ry = matrix[midx].size();
                int midy = (ly + ry) / 2;
                
                while (ly < ry) 
                {
                    
                    if (matrix[midx][midy] == target)
                        return true;
                    if (matrix[midx][midy] < target)
                        ly = midy + 1;
                    else
                        ry = midy;
                    
                    midy = (ly + ry) / 2;
                }
                return false;
            }
            
            if(matrix[midx].back() < target) 
                lx = midx + 1;
            
            else if(matrix[midx][0] > target)
                rx = midx;
            
            midx = (lx + rx) / 2;
        }
    return false;  
    }
};