class Solution {
public:
  string help(string a)
    {
        string tmp ="";
        int atflag=0, pflag=0;
        for(char c:a)
        {
            if(c=='@')
                atflag=1;
            
            if(!atflag)
            {
                
              if(c=='.')
                  continue;
              if(c=='+')
                  pflag=1;
               if(pflag==1)
                    continue;
                
                tmp = tmp + c;
            }
            else
                tmp = tmp + c;
                
        }
    return tmp;
    }
    
    int numUniqueEmails(vector<string>& emails) 
    {
        unordered_map<string, int>mp;
        
        for(auto x:emails)
            mp[help(x)]++;
        
        return mp.size();
    }
};