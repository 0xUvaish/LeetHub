// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a, a+n);
        for (int i = 0; k > 0 && i < n && a[i] < 0; ++i, --k)
            a[i] = -a[i];
            
        long long int res = 0, x = INT_MAX;
        for (int i=0;i<n;i++) 
        {
            res += a[i];
            x = min(x, a[i]);
        }
        return res - (k % 2) * x * 2;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends