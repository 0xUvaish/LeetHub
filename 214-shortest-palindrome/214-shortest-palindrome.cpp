class Solution {
public:
    
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
    
    string shortestPalindrome(string s)
    {
        
        string temp = s;
        reverse(temp.begin(), temp.end());
        string l = s + "#" + temp;
        
        int n=l.size();
        auto lps = kmp_algo(l);
        int x = lps[n-1];  //LPS of given string 
        
        string y = s.substr(x);
        reverse(y.begin() , y.end());
        return y + s;
        
        
    }
};