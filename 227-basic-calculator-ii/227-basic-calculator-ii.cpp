class Solution {
public:

    int calculate(string s) 
    {
        s+="+";
        
        stack<int> stack;
        int currNumber=0;
        char sign ='+';
        
        for( int i = 0 ; i < s.length() ; i++ )
        {
            if(s[i]==' ')
                continue;
            
            else if(s[i]>='0')
                currNumber = currNumber*10 + (s[i] - 48);
            
            else 
            {
                if(sign=='+')
                    stack.push(currNumber);
                
                else if(sign=='-')
                    stack.push(-currNumber );
                
                else if(sign=='*')
                {
                    int a = stack.top(); stack.pop();
                    stack.push(a*currNumber);
                }
                
                else if(sign == '/')
                {
                    int a = stack.top(); stack.pop();
                    stack.push(a/currNumber);
                }
                
                currNumber = 0;
                sign = s[i];
            }
        }
        
        int result = 0;
        while(!stack.empty())
        {
            result += stack.top();
            stack.pop();
        }
        
        return result;
        
    }
};