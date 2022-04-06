class Solution {
public:
int strStr(string haystack, string needle) 
{
        int l1=haystack.size();
        int l2=needle.size();
    
        if(l2==0)
            return 0;
    
        int ans=-1;
    
        for(int i=0;i<l1;i++)
        {
            if(haystack[i]==needle[0])
            {
                int s1=i,s2=0;
                
                while(s1<l1 && s2<l2 && haystack[s1]==needle[s2])
                {
                    s1++;
                    s2++;
                }
                
                 if(s2==l2)
                    return (s1-s2); //or return i; 
            }
            
        }
        
    return -1;
    }
};