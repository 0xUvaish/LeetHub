// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S)
    {
       
        int left=0,right=0,n=S.size(),swaps=0;
        for(int i=0;i<n;i++) 
        {
            if(S[i]=='[')
            {
                if(right>left)
                    swaps+=(right-left);
                    
                left++;
            }
            
            else
                right++;
        }
        
    return swaps;
   
  }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
}   // } Driver Code Ends