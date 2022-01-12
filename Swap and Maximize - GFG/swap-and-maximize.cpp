// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    vector<int> ans;
    sort(arr, arr+n);
    for(int i=0;i<n/2;i++)
    {
        ans.push_back(arr[i]);
        ans.push_back(arr[n-1-i]);
    }
    
    if(n%2!=0)
        ans.push_back(arr[n/2]);
    long long int sum=0;
    
    for(int i=0;i<n-1;i++)
        sum += abs(ans[i+1] - ans[i]);
        
    sum += abs(ans[n-1] - ans[0]);
    
return sum;
}