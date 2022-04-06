class Solution {
public:
    bool isAnagram(string s, string t) {
    
    if(s.size()!=t.size()) 
        return 0;
        
    vector<int> a(26,0);
    vector<int> b(26,0);
        
    for(int i=0;i<s.size();i++)
    {
       a[s[i]-'a']++;
       b[t[i]-'a']++;
    }
        
    for(int i=0;i<=25;i++)
        if(a[i]!=b[i])
            return 0;
        
    return 1;
    }
};