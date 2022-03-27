class Solution {
public:

    vector<string> ans;

void solve(string &s, set<string> &ss, int index, string asf)
{
    if(s[index]=='\0')
    {
        asf = asf.substr(0, asf.size()-1);
        ans.push_back(asf);
        return;
    }
    
    string temp="";
    for(int i=index; s[i]!='\0';i++)
    {
        temp += s[i];
        if(ss.find(temp)!=ss.end())
        {
            solve(s, ss, i+1, asf+temp+" ");
        }
    }
}
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
    
        set<string> ss;
    for(auto x: wordDict)
        ss.insert(x);
    
    solve(s, ss, 0, "");
    return ans; 
    }
    

};