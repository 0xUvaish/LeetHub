class Solution {
public:
    vector<string> sans;
    void Util(string s, string s1, int index)
    {
        sans.push_back(s1);
        for(int i=index;i<s.length();i++)
        {
            if(s[i]>=97 && s[i]<=122)
            {
                s1[i]=s[i]-32;
                Util(s,s1,i+1);
                s1[i]=s[i];
            }
            else if(s[i]>=65 && s[i]<=90)
            {
                s1[i]=s[i]+32;
                Util(s,s1,i+1);
                s1[i]=s[i];
            }
        }
    }
    
    vector<string> letterCasePermutation(string s) 
    {
        Util(s,s,0);
        return sans;
    }
};