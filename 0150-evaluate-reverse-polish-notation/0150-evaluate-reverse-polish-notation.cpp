class Solution {
public:
    int evalRPN(vector<string>& tokens) {
     
        int n = tokens.size();
        stack<long> st;
        long a,b;
        
        for(auto x: tokens)
        {
            
            if(x=="+")
            {
               b = st.top(); 
                st.pop();
               a = st.top();
                st.pop();
                
             st.push(a+b);
               
            }  
            else if(x=="-")
            {
               b = st.top(); 
                st.pop();
               a = st.top();
                st.pop();
                
             st.push(a-b);               
            } 
            else if(x=="*")
            {
               b = st.top(); 
                st.pop();
               a = st.top();
                st.pop();
                
             st.push(a*b);                
            }   
            else if(x=="/")
            {
               b = st.top(); 
                st.pop();
               a = st.top();
                st.pop();
                
             st.push(a/b);                
            }
            
            else
            {
              long y = stoi(x);
              st.push(y);                
            }
                
        }
        
    return st.top();
        
    }
};