// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
  bool globalFlag = false;
    void solve(int a[], int ind, int n, int k, vector<int> &sum, int numOfPartition, vector<int> partition[])
    {
        if(ind==n)
        {
            if(numOfPartition == k)
            {
                bool flag = true;
                for(int i=0; i<k-1; i++)
                {
                    if(sum[i] != sum[i+1])
                    {
                        flag=false;
                        break;
                        
                    }
                    
                }
                if(flag)
                    globalFlag=true; 
                
            }
                return;
            
        }
        
        for(int i=0;i<k; i++)
        {
            if(partition[i].size()> 0)
            {
                partition[i].push_back(a[ind]);
                sum[i] += a[ind];
                solve(a, ind+1, n, k, sum, numOfPartition, partition);
                sum[i] -= a[ind];
                partition[i].pop_back();
            }
            else
            {
                partition[i].push_back(a[ind]);
                sum[i] += a[ind];
                solve(a, ind+1, n, k, sum, numOfPartition+1, partition);
                sum[i] -= a[ind];
                partition[i].pop_back();
                break;
            }
        }
    }
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
        vector<int> partition[k];
        int sum = 0;
        for(int i=0; i<n; i++)
            sum +=a[i];
            
        if(n<k || sum%k!=0)
            return false;
            
        int reqsum = sum/k; 
        vector<int> req(k, 0);
        solve(a, 0, n, k, req, 0, partition);
        return globalFlag;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends