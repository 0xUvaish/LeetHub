// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:

    vector<int> candyStore(int candies[], int N, int K)
    {
       sort(candies, candies+N);
       int min=0,max=0,low=0,high=N-1;
       int remCand=N;
       while(remCand>0)
       {
           min += candies[low++];
           max += candies[high--];
           remCand -= (K+1);
       }
    return {min, max};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends