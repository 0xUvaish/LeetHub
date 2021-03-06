class Solution {
public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size();
        int n=mat[0].size();
        if(m*n != r*c)
            return mat;
      
        vector<vector<int>>ans;
        vector<int>res;
      
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                res.push_back(mat[i][j]);
                if(res.size()==c)
                {
                    ans.push_back(res);
                    res={};
                }
            }   
        }
      
    return ans;
    }
};