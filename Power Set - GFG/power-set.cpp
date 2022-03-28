// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	    vector<string> ans;
	    void help(int index, string &word, string &s)
	    {
	            
	        ans.push_back(word);
	        if(index==s.size())
	            return;

	        for(int i=index+1;i<s.size();i++)
	        {
	            word.push_back(s[i]);
	            help(i,word,s);
	            word.pop_back();
	        }
	        
	       return;
	    }
		vector<string> AllPossibleStrings(string s){
		   string word="";
		   string b =s;
		   for(int i=0;i<b.size();i++)
		   {
		    word.push_back(b[i]);
		    help(i, word, b);
		    word.pop_back();
		   }
		   sort(ans.begin(), ans.end());
		   return ans; 
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends