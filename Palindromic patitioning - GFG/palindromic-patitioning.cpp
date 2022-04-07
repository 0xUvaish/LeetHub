// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dp[501][501];
bool ispalin(string &str , int l , int r)
{
   while(l<r)
   {
       if(str[l]!=str[r])
           return false;
           
       l++;
       r--;
   }
   
   return true;
}
   int func(int l , int r , string &str )
   {
       if(l==r)
           return dp[l][r]= 0;
       
       if(ispalin(str , l ,r))
           return 0;
       
       if(dp[l][r]!=-1)
           return dp[l][r];
       
       int res=INT_MAX;
       for(int k=l;k<r;k++)
           res=min(res , 1 + func(l , k , str) + func(k+1 , r , str));
       
      return dp[l][r]=res;
   }
   
   int palindromicPartition(string str)
   {
       // code here
       memset(dp , -1 , sizeof(dp));
       int n=str.size();
       return func(0 , n-1 , str);
   }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends