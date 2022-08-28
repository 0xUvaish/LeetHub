class Solution {
public:
    
    //Sol 1: Insertion Sort O(n^3) Sol
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {

    for(int t=1;t<mat.size();t++)
    {
        for(int i=1;i<mat.size();i++)
        {
            for(int j=1;j<mat[0].size();j++)
            {
                if(mat[i][j]<mat[i-1][j-1])
                    swap(mat[i][j],mat[i-1][j-1]);
            }
        }
    }
    return mat;
    }
};