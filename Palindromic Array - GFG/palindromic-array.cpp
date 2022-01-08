// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}// } Driver Code Ends


/*Complete the function below*/
int PalinArray(int a[], int n)
{  
    int cnt=0;
    
    for(int i=0;i<n;i++)
    {
        int temp = a[i];
        int rem,sum=0;
    
        while(temp!=0)
        {
            rem = temp%10;
            temp/=10;
            sum = sum*10 + rem; 
        }
        
        if(sum == a[i])
            cnt++;
        
    }
    
return cnt==n?1:0;

}