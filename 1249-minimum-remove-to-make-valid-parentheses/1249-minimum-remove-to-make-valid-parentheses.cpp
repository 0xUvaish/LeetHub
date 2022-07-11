class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int,int>>st;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push({s[i],i});
            
            else if(s[i]==')')
            {
                if(!st.empty() && st.top().first=='(')
                    st.pop();
                else
                    st.push({s[i],i});
            }
        }
        
        //Unbalanced will remain in stack
        while(!st.empty())
        {
            int a=st.top().second;
            s.erase(s.begin()+a);
            st.pop();
        }
        return s;
    }
};