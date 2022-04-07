// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[101][101];

int func(int arr[] , int n , int i , int j )
{
   if(i+1==j)
       return 0;
   
   if(dp[i][j]!=-1)
       return dp[i][j];
   
   int res = INT_MAX;
   for(int k=i+1;k<j;k++)
       res = min(res ,(arr[i]*arr[k]*arr[j] ) + func(arr,n,i,k) + func(arr,n,k,j));
   
   return dp[i][j]=res;
}
   int matrixMultiplication(int n, int arr[])
   {
       memset(dp , -1 , sizeof(dp));
       return func(arr , n , 0 , n-1);
   }
   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}  // } Driver Code Ends