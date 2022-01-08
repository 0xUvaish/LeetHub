// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
		int find_median(vector<int> v)
        {
            sort(v.begin(),v.end());
            int avg;
            int n = v.size();
            if(n%2==0)
            {
                avg = v[(n/2)-1]+v[(n/2)];
                avg = avg/2;
                return avg;
                
            }
            else
            {
                avg = v[((n+1)/2)-1];
                return avg;
            }
        }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}
  // } Driver Code Ends