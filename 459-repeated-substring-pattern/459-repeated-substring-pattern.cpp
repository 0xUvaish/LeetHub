class Solution {
public:
    //Standard KMP/LPS Algo to get LPS of string s
    vector<int> kmp_algo(string s)
    {
        int j=0, i=1, m=s.size();
        vector<int> lps(m,0);
        
        while(i<m)
        {
            if(s[i]==s[j])
            {
                j++;
                lps[i]=j;
                i++;
            }
            else if(j!=0)
                j=lps[j-1];
            else
            {
                lps[i]=0;
                i++;
            }
            
        }
        
    return lps;
    }
    
    bool repeatedSubstringPattern(string s) 
    {
        int n=s.size();
        auto lps = kmp_algo(s);
        
        int len = n-lps[n-1];
        if(lps[n-1]%len == 0 && lps[n-1]!=0) 
            return true;
        
        return false;
    }
};