class Solution {
public:

    int calculate(string s) 
    {
        s += "+";  //As acc to our logic last number will be left
        
        int n = s.size();
        stack<int> stack;
        
        int currNumber=0;
        char sign ='+';
        
        for(int i=0;i<n; i++)
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
        
        //Multiply and Division are already taken care of in above, here just need to do + and -
        int result = 0;
        while(!stack.empty())
        {
            result += stack.top();
            stack.pop();
        }
        
        return result;
        
    }
};