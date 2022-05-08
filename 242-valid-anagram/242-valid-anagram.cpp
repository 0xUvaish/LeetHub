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
      
    return a==b;
    }
};