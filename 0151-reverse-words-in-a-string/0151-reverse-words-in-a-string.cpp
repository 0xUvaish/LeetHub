class Solution {
public:
    //M1: Using Extra Space
//     string reverseWords(string s) {
//         string res;
//         string temp;
//         for(int i=0;i<s.size();i++)
//         {
   
//             if((s[i]>=97 && s[i]<=122) || (s[i]>=65 && s[i]<=90) || (s[i]>=48 && s[i]<=57))
//                 temp += s[i];
            
//             if((s[i]==' ' || i==s.size()-1) && temp.size())
//             {
//                 res = temp + ' ' + res;
//                 temp.clear();
//             }
//         }
        
//     res = res.substr(0,res.size()-1);
//     return res;
        
//     }
    
    //M2: Without any Space
    void rtrim(string &s)
    {
        while(true)
        {
            if(s[s.length()-1]==' ')
                s.pop_back();
            
            else break;
        }
    }
    void ltrim(string &s)
    {
        while(true)
        {
            if(s[0]==' ')
                s.erase(s.begin());

            else break;
        }
    }
    void cleanMid(string &s)
    {
        int count=0;
        for(int i=1;i<s.length();i++)
        {
            if(s[i-1]==' ' && s[i]==' ')
            {
                s.erase(i,1);
                i--;
            }
        }
        
    }
    
    void reverse(string &s, int start, int end)
    {
        while(start<end)
        {
            swap(s[start++], s[end--]);
        }
    }
    
    string reverseWords(string s)
    {
        ltrim(s);
        rtrim(s);
        cleanMid(s);
        reverse(s, 0, s.length()-1);

        int start=0, end=0;
        int i=0;
        while(i<s.length())
        {
            if(s[i]==' ' )
            {
                end=i-1;
                reverse(s, start, end);
                start=i+1;
            }
            i++;
        }

        reverse(s,start, s.length()-1);
        return s;
    }
};