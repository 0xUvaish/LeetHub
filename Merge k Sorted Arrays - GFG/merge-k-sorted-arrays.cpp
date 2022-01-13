// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    typedef pair<int,pair<int,int>> node;  // {value, {arrayno,indexofelement in that array}}
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<node,vector<node>,greater<node>> q;
        vector<int> result;
         
         for(int i=0;i<K;i++)
             q.push({arr[i][0],{i,0}});
         
         while(!q.empty())
         {
             node current = q.top();
             q.pop();
             
             int value = current.first;
             int arrayNo = current.second.first;
             int index = current.second.second;
             
             result.push_back(value);
             
             if(index+1<K)
                 q.push({arr[arrayNo][index+1],{arrayNo,index+1}});
             
         }
         
    return result;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends