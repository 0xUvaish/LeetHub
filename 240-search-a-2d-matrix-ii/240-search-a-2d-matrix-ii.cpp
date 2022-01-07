class Solution {
public:
    
bool search(vector<vector<int>>& matrix, int target, int i, int j)
{
         if(j<0 || i>matrix.size()-1)
             return false;
         if(matrix[i][j]==target)
            return true;
         else if(matrix[i][j]>target)
             return search(matrix,target,i,j-1);
         else
             return search(matrix,target,i+1,j);
        return false;
} 
    
 bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
       return search(matrix,target,0,matrix[0].size()-1);        
    }
    
};