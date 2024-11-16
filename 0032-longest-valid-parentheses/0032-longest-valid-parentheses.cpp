class Solution {
public:
    int longestValidParentheses(string s) 
    {
        
        vector<bool> is_paired(s.size(), false);
        stack<int> st;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(') 
                st.push(i);
            
            else if(!st.empty())
            {
                is_paired[st.top()] = true;
                is_paired[i] = true;
                st.pop();
            }
         }
        
        //now simply count continuous paired indexes(which is true in is_paired vector) 
        int cur = 0, mx = 0;
        
        for(int i = 0; i<s.size(); i++)
        {
            if(is_paired[i])
                cur++;
            else
            {
                mx = max(mx, cur);
                cur = 0;
            }
        }
        
        if(cur)  //To include last index 
            mx = max(mx, cur);
            
        return mx;
    }
};