class Solution {
public:
    //M1: DP O(n^2)
//     int numTrees(int n) {
                
//         vector<int> ans(n+1);
//         ans[0] = 1; ans[1] = 1;
//         for(int i=2; i<=n; i++){
//             for(int j=0; j<i; j++){
//                 ans[i] += ans[j]*ans[i-1-j];
//             }
//         }
//         return ans[n];
//     }
    
//M2: Binomial Coefficient
// Cn = (2nCn)/(n+1)
    int numTrees(int n) {
        long long int a = 1;
        for(int i = 1; i <= n; i++){
            a *= (n+i);
            a /= (i);
        }
        a /= n+1;
        return a;
    }
};