// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
     int maxSumIS(int arr[], int n)  
        {  
            int dp[n];
            int maxi = 0;
            dp[0] = arr[0];
            int ans = arr[0];
            
            for(int i=1;i<n;i++)
            {
                maxi = 0;
                for(int j=0;j<i;j++)
                    if(arr[i]>arr[j])
                        maxi = max(dp[j],maxi);
                        
                        
                dp[i] = maxi + arr[i];
                ans = max(ans, dp[i]);
            }
            
            return ans;
        }  

};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends