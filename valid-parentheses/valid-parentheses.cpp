class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                st.push(s[i]);
            else if(!st.empty())
            {
                if(s[i]==')')
                {
                    if(st.top()!='(')
                        return false;
                    else
                        st.pop();
                }
                
                if(s[i]=='}')
                {
                    if(st.top()!='{')
                        return false;
                    else
                        st.pop();
                }
                
                if(s[i]==']')
                {
                    if(st.top()!='[')
                        return false;
                    else
                        st.pop();
                }
            }
            
            else
                return false;
        }
        
        
return st.empty();
        
    }
};