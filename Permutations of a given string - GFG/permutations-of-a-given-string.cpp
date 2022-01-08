// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    void permute(string s, int l ,int r, vector<string >&ans)
       {
           if(l==r)
               ans.push_back(s); 
               
           else 
           {
                for(int i=l;i<=r;i++)
                {
                    swap(s[l], s[i]); 
                    permute(s, l+1, r, ans) ; 
                    swap(s[l], s[i]); 
                }
           }
       }
       
public:
 vector<string>find_permutation(string s)
 {
     vector<string >ans ; 
     permute(s, 0, s.size()-1, ans); 
     sort(ans.begin(), ans.end()); 
     return ans; 
 }
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends