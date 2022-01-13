// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    
    #define pii pair<int, pair<int, int>>
    
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
         priority_queue<pii, vector<pii>, greater<pii>> pq;
         int cmax=INT_MIN;
         int cmin=INT_MAX;
         
         for(int i=0;i<k;i++)
         {
             pq.push({arr[i][0], {i,0}});
             cmax = max(cmax, arr[i][0]);
         }
         
         int range = INT_MAX;
         int start=0,end=0;
         while(true)
         {
             pii temp = pq.top();
             pq.pop();
             cmin = temp.first;
             if(cmax-cmin<range)
             {
                 start=cmin;
                 end=cmax;
                 range = cmax-cmin;
             }
             
             if(temp.second.second+1==n)
                break;
            pq.push({arr[temp.second.first][temp.second.second+1], {temp.second.first, temp.second.second+1}});
            if(arr[temp.second.first][temp.second.second+1]>cmax)
                cmax=arr[temp.second.first][temp.second.second+1];
         }
         pair<int, int> ans = {start, end};
         return ans;
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
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends