class Solution {
public:
    vector<int> kmp_algo(string s)
    {
        int j=0, i=1, n=s.size();
        vector<int> lps(n,0);
        
        while(i<n)
        {
            if(s[i]==s[j])
            {
                lps[i]=j+1;
                i++;
                j++;
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