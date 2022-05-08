class Solution {
public:
    string decodeString(string s) {
        
        string ans="";
        int num=0;
        stack<pair<string,int>>stk;
        
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
                num=(num*10)+(s[i]-48);
           else if(isalpha(s[i]))
                ans+=s[i];
            
           else if(s[i]=='[')
            {
                stk.push({ans,num});
               
                ans="";
                num=0;
            }
            else if(s[i]==']')
            {
                string tmp=ans;
                int k = stk.top().second;
                for(int i=0;i<k-1;i++)
                    tmp += ans;
                
                ans=stk.top().first+tmp;
                stk.pop();
                
            }
                
        }
     
        return ans;
    }
};