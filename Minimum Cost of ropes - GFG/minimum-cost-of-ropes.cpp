// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
    long long sum = 0;
       if(n==1) 
        return sum;
        
       priority_queue<long long,vector<long long>, greater<long long>> minh;
       for(long long i=0; i<n; i++)
        minh.push(arr[i]);
       while(minh.size() >1)
       {
           long long x = minh.top();
           minh.pop();
           long long y = minh.top();
           minh.pop();
           sum += (x+y);
           minh.push(x+y);
       }
       return sum;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends