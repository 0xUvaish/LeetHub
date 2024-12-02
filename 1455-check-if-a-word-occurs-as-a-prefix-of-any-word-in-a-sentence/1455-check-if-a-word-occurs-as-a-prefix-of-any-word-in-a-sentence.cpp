class Solution {
public:
    bool isprep(string s,string w)
    {
        string temp=s.substr(0,w.size());
        return temp==w;
    }
    
    int isPrefixOfWord(string s, string w) {
        int res=0;
        for(int i=0; i<s.size(); i++)
        { 
            string temp="";
            while(s[i]!=' ' and i<s.size())
            {
                temp.push_back(s[i]);
                i++;
            }
            res+=1;
            if(isprep(temp,w))
                return res;
        }
        return -1;
    }
};