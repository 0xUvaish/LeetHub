class Solution {
public:
    int numSubmat(vector<vector<int>>& matrix) 
    {
        
        if(matrix.empty())  
            return 0;
        
        int m = matrix.size();
        int n = matrix[0].size(); 
        int ans = 0;
       
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) 
        {            
            for (int j = 0; j < n; j++) 
            {
                if(!j || !matrix[i][j])    // update dp horizontally in the range of j 
                    dp[i][j] = matrix[i][j];     // if we get a 0 we put a 0      
                else 
                    dp[i][j] =  1 + dp[i][j - 1];   // if not a 0 we add 1 in the last dp
// basically this is the width of a retangle with one 1 unit breadth
// we travel all the rows and calcluate the width of rectangle possible in each row (rectangle will be in that row only breadth = 1)
                          
                int width = dp[i][j];       // stores the width of that cell
                for(int k = i; k >= 0; k--)
                {        // travel the previous rows to get a combination of breadth
                    width = min(dp[k][j], width); // to form a rectangle all rows should have same width 
// min width and inc breadth will form a rectangle 
                    ans += width;  // this will add all the possible rectangles as we inc rows and colunmns
                }
            }
        }
        return ans;
    }
};