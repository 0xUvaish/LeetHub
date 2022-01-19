class Solution {
public:
bool backspaceCompare(string s, string t)
{
        for(int i=0;i<s.size();i++)
        {
            if(s[0]=='#')
            {
                s.erase(0,1);
            }
            
            if(s[i]=='#' && i>=1)
            {
                s.erase(i-1, 2);
                i=i-2;
            }
        }
        for(int i=0;i<t.size();i++)
        {
             if(t[0]=='#')
             {
                t.erase(0,1);
             }
           
            if(t[i]=='#' && i>=1)
            {
                t.erase(i-1, 2);
                i=i-2;
            }
        }
    
        if(s==t)
            return true;
        else
            return false;
    }
};