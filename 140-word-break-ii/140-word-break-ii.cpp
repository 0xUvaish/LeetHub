class Solution {
public:

vector<string> ans;

void solve(string &s, set<string> &dict, int index, string asf)
{
    if(s[index]=='\0')
    {
        asf = asf.substr(0, asf.size()-1);
        ans.push_back(asf);
        return;
    }
    
    string temp="";
    for(int i=index; i<s.length();i++)
    {
        temp += s[i];
        if(dict.find(temp)!=dict.end())
        {
            solve(s, dict, i+1, asf+temp+" ");
        }
    }
}
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    
    set<string> dict;
    for(auto x: wordDict)
        dict.insert(x);
    
    solve(s, dict, 0, "");
    return ans; 
    }
    

};