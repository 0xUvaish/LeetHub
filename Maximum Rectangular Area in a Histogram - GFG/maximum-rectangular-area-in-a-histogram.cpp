// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
   long long getMaxArea(long long arr[], int n)
   {
       arr[n] = 0;
       stack<int> st;
       st.push(-1);
       long long ans = 0;
       for(int i=0;i<=n;i++)
       {
           while(st.size()>1 && arr[st.top()]>=arr[i])
           {
               int ind = st.top();
               st.pop();
               ans = max(ans,arr[ind]*(i-st.top()-1));
           }
           st.push(i);
       }
       return ans;
   }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
  // } Driver Code Ends