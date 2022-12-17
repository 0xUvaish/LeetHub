class Solution {
public:

    //Method 1 -> Brute-Force O(n^2) Solution
//     int strStr(string haystack, string needle) 
//     {
//         int l1=haystack.size();
//         int l2=needle.size();
    
//         if(l2==0)
//             return 0;
    
//         int ans=-1;
    
//         for(int i=0;i<l1;i++)
//         {
//             if(haystack[i]==needle[0])
//             {
//                 int s1=i,s2=0;
                
//                 while(s1<l1 && s2<l2 && haystack[s1]==needle[s2])
//                 {
//                     s1++;
//                     s2++;
//                 }
                
//                  if(s2==l2)
//                     return (s1-s2); //or return i; 
//             }
            
//         }
        
//     return -1;
//     }
    
    
    //Method 2 - Using KMP Algo - O(n) Solution
    
    //Standard KMP/LPS Algo to get LPS of string s
    vector<int> get_lps(string s)
    {
        int j=0, i=1, n=s.size();
        vector<int> lps(n,0);
        
        while(i<n)
        {
            if(s[i]==s[j])
            {
                lps[i++]=++j;
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
    
    int strStr(string haystack, string needle) 
    {
        int n = haystack.size();
        int m = needle.size();
        
        if(m>n)
            return -1;
        if(m==n)
            return (haystack==needle? 0: -1);
        
        auto lps = get_lps(needle);
        int i=0,j=0;
        
        while(i<n && j<m)
        {
            if(haystack[i]==needle[j])
            {
                j++;
                i++;
            }
            else if(j!=0)
                j=lps[j-1];
            else
                i++;
        } 
        
    return (j<m ? -1 : i-m);
    }
};