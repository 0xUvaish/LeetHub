class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> subst;
        if (k > s.length()) 
            return false;
        
        for (int i=0; i<=s.length()-k; ++i)
            subst.insert(s.substr(i, k));
        
        return subst.size() == 1 << k;
    }
};