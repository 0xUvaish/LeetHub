class Solution {
public:
    string reverseWords(string s) {
        string res;
        string temp;
        for(int i=0;i<s.size();i++)
        {
   
            if((s[i]>=97 && s[i]<=122) || (s[i]>=65 && s[i]<=90) || (s[i]>=48 && s[i]<=57))
                temp += s[i];
            
            if((s[i]==' ' || i==s.size()-1) && temp.size())
            {
                res = temp + ' ' + res;
                temp.clear();
            }
        }
        
    res = res.substr(0,res.size()-1);
    return res;
        
    }
};