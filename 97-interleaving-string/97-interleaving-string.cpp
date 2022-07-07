class Solution {
public:
    //Solution 1: Top Down O(n^2) TC, O(n^2) SC
//     int dp[102][102];
//     bool solve(string &s1, string &s2, string &s3, int i, int j, int k){
        
//         if(k >= s3.size()) 
//             return true;
        
//         if(dp[i][j] != -1) 
//             return dp[i][j];
        
//         bool flag1 = false, flag2 = false;
        
//         if(s1[i] == s3[k])
//             flag1 =  solve(s1, s2, s3, i + 1, j, k + 1);
        
//         if(s2[j] == s3[k])
//             flag2 =  solve(s1, s2, s3, i, j + 1, k + 1);
    
//         return dp[i][j] = (flag1 || flag2);
        
//     }
//     bool isInterleave(string s1, string s2, string s3)
//     {
//          if((s1.size() + s2.size()) != s3.size()) 
//              return false;
        
//          memset(dp, -1,sizeof(dp));         
//          return solve(s1, s2, s3, 0 , 0 , 0);
//     }
    
    
// Method 2: Bottom Up: O(n) Space
    bool isInterleave(string s1, string s2, string s3) {
        int size1 = s1.size();
        int size2 = s2.size();
        int size3 = s3.size();
        
        if(size3 != size1 + size2) return false;
        
        //vector<vector<bool>> dp(size1 + 1, vector<bool>(size2 + 1));
        vector<bool> dp(size2 + 1);
        dp[0] = 1;
        for(int i = 0; i <= size1; i++){
            for(int j = 0; j <= size2; j++){
                if(i == 0 && j == 0)
                    continue;
                
                else if(i == 0) 
                    dp[j] = dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                else if(j == 0){
                    int curr = dp[j];
                    dp[j] = curr && s1[i - 1] == s3[i + j - 1];
                }
                else{
                    int prev = dp[j];
                   dp[j] = ((prev && s1[i - 1] == s3[i + j - 1])
                                ||
                               (dp[j - 1] && s2[j - 1] == s3[i + j - 1]));
                }
            }
            
        }
        return dp[size2];
    }
};