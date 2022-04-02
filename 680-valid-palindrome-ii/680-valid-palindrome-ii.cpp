class Solution {
private:
    bool isPalindrome(string& s, int lo, int hi) 
    {
        while (lo <= hi) 
        {
            if (s[lo] != s[hi])
                return false;
            
            ++lo, --hi;
        }
        
        return true;
    }
    
public:
    bool validPalindrome(string s) 
    {
        int lo = 0, hi = size(s) - 1;
        while (lo <= hi)
        {
            if (s[lo] == s[hi])
                ++lo, --hi;
            else 
                return isPalindrome(s, lo + 1, hi) | isPalindrome(s, lo, hi - 1);
        }
        
        return true;
    }
};