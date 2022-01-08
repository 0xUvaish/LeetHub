// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
vector<vector<int> > fourSum(vector<int> &arr, int k) {
       // Your code goes here
       sort(arr.begin(),arr.end());
       int num=arr.size();
       vector<vector<int>>vs;
       
       for(int i=0;i<num-3;i++)  //4 sum
       {
           for(int j=i+1;j<num-2;j++)  //3 sum
           {
               int l=j+1,h=num-1;
               while(l<h)           // 2 sum
               {
                   if(arr[l]+arr[h]+arr[i]+arr[j]<k)
                       l++;
                   else if(arr[l]+arr[h]+arr[i]+arr[j]>k)
                       h--;
                   else
                   {
                       vector<int>vs1(4,0);
                       vs1[0]=arr[i];
                       vs1[1]=arr[j];
                       vs1[2]=arr[l];
                       vs1[3]=arr[h];
                       vs.push_back(vs1);
                       // increase & descrease l , h for repeated elements
                       while(l<h && arr[l]==vs1[2])
                           l++;
                       while(l<h && arr[h]==vs1[3])
                           h--;
                   }
                       
               }
               while(j+1<num && arr[j]==arr[j+1])
                   j++;
           }
           while(i+1<num && arr[i]==arr[i+1])
                   i++;
       }
       return vs;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends