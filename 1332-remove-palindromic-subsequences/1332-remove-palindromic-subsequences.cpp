class Solution {
public:
    bool isPal(string s)
    {
        int i=0,j=s.size()-1;
        while(i<=j)
        {
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    
    int removePalindromeSub(string s) 
    {
        if(isPal(s))
            return 1;
        return 2;
    }
};