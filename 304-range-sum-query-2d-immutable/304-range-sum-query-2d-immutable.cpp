class NumMatrix {
public:
    // pref matrix declaration
    vector<vector<int>> pref;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
            
        pref.assign(r, vector<int>(c, 0));
        
        // first col prefix sum
        for(int i=0; i<r; i++){
            pref[i][0] = matrix[i][0] + (i-1>=0 ? pref[i-1][0] : 0);
        }
        
        // first row prefix sum
        for(int i=0; i<c; i++){
            pref[0][i] = matrix[0][i] + (i-1>=0 ? pref[0][i-1] : 0);
        }
    
        // prefix sum precomputation
        for(int i=1; i<r; i++){
            for(int j=1; j<c; j++){
                pref[i][j] = matrix[i][j]+(i-1>=0?pref[i-1][j]:0) + (j-1>=0?pref[i][j-1]:0) 
                    - ((i-1>=0 && j-1>=0)?pref[i-1][j-1] : 0);
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return pref[row2][col2] - (row1-1>=0 ? pref[row1-1][col2]:0) - 
            (col1-1>=0?pref[row2][col1 - 1]:0) + ((row1-1>=0 && col1-1>=0)? pref[row1-1][col1-1] : 0);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */