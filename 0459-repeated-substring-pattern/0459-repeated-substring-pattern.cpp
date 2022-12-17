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
                lps[i++]=++j;

            else if(j!=0)
                j=lps[j-1];
        
            else
                lps[i++]=0; 
        }
        
    return lps;
    }
    
    bool repeatedSubstringPattern(string s) 
    {
        int n=s.size();
        
        auto lps = kmp_algo(s);
        int k = lps[n-1];  //LPS of given string   
        
        //Repeated Substring only if n is divisible by n-k
        if(k!=0 && n%(n-k)==0) 
            return true;
        
        return false;
    }
};