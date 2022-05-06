class Solution {
public:
    //Method 1: Direct STL 
    bool isMatch(string s, string p) 
    {
	regex obj(p);
	if(regex_match(s, obj))
		return true;
	else
		return false;
    }
    
    //Method 2: 
};