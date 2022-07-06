class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> subst;
        int n = s.length();
        if (k > n) 
            return false;
        
        for (int i=0; i<=n-k; ++i)
            subst.insert(s.substr(i, k));
        
        return subst.size() == (pow(2,k));
    }
};