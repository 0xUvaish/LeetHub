class Solution {
public:
    bool isSubsequence(string s, string t) {
        int start = 0;
	    for(char val : t) 
            start += (s[start] == val);
        
	return start == s.size();
    }
};