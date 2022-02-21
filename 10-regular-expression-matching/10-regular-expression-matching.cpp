class Solution {
public:
    bool isMatch(string s, string p) {
	regex b(p);
	if(regex_match(s, b))
		return true;
	else
		return false;
    }
};