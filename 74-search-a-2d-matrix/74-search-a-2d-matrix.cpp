class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int lx = 0, rx = m-1;
        while (lx <= rx)
          {
            int midx = (lx + rx) / 2;
            
            if(matrix[midx][0] <= target && target <= matrix[midx][n-1])
            {
                int ly = 0, ry = n-1;
                while (ly <= ry) 
                {
                    int midy = (ly + ry) / 2;
                    
                    if (matrix[midx][midy] == target)
                        return true;
                    
                    else if(matrix[midx][midy] < target)
                        ly = midy + 1;
                    else
                        ry = midy - 1;
                    
                }
                
                return false;
            }
            
            else if(matrix[midx][n-1] < target) 
                lx = midx + 1;
            
            else
                rx = midx-1;
            
        }
        
    return false;  
    }
};