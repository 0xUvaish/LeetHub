class Solution {
public:
     int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        
        vector<vector<int>> dp(row, vector<int>(col, 0));
        
        for(int i=0; i<col; i++){
            dp[row-1][i] = matrix[row-1][i] - '0';
        }
        for(int i=0; i<row; i++){
            dp[i][col-1] = matrix[i][col-1] - '0';
        }
        
        for(int i=row-2; i>=0; i--){
            for(int j = col-2; j>=0; j--){
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = min({dp[i][j+1], dp[i+1][j+1], dp[i+1][j]}) + 1;
                }
            }
        }
        // Maximum is the answer
        int ans = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans*ans;
    }
};