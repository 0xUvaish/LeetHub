// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
     void word_util(string & s, int i1, string & temp, unordered_map<string, int>& mp, vector<string>& res)
     {
        if(i1 == s.length())
        {
            res.push_back(temp.substr(0, temp.length()-1));
            return;
        }
        
        string cur = "";
        for(int i = i1; i < s.length(); i++)
        {
            cur += s[i];
            if(mp[cur])
            {
                string pass = temp + cur + " ";
                word_util(s, i + 1, pass, mp, res);
            }
        }
        
        
    }


    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
    unordered_map<string, int>mp;
        for(auto a : dict)
            mp[a]++;
            
        string temp = "";
        vector<string>res;
        word_util(s, 0, temp, mp, res);
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends