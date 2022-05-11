class Solution {
public:
 
//Method 1 - Recursion - 5^n Solution
// int vowels(int index,int n)
// {
//     if(n==0)
//         return 1;
    
//     int count=0;
//     for(int i=index;i<5;i++)
//         count+=vowels(i,n-1);
    
//     return count;
// }
    
// int countVowelStrings(int n)
// {
    
//  int count=0;
// 	for(int i=0;i<5;i++)
//         count+=vowels(i,n-1);
    
//     return count;
// } 
    
//Method 2 - DP Solution - O(n)
//     int countVowelStrings(int n) {
//         int dp[n][5];
//         if(n==1)
//             return 5;
        
//         for(int i=0;i<5;i++)
//             dp[0][i]=1;
        
//         for(int i=1;i<n;i++)
//         {
//                 dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4];
//                 dp[i][1]=dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][4];
//                 dp[i][2]=dp[i-1][2]+dp[i-1][3]+dp[i-1][4];
//                 dp[i][3]=dp[i-1][3]+dp[i-1][4];
//                 dp[i][4]=dp[i-1][4];
//         }
        
//         int sum=0;
//         for(int j=0;j<5;j++)
//             sum+=dp[n-1][j];
        
//         return sum;
//     } 
    
    //Method 3 - PnC - Combination with repetition - !(n-1+r)/!(r)!(n-1) 
    // n = 5, r = n(n provided in question)
    // === ((n+1)*(n+2)*(n+3)*(n+4))/4
    int countVowelStrings(int n) {
        return ((n+1)*(n+2)*(n+3)*(n+4))/24;
    }
};