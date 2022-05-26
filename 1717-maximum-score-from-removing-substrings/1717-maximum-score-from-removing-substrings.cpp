class Solution {
public:
int maximumGain(string s, int x, int y) 
{
        string mx = "";
        string mn = "";
        int smx=0,smn=0;
    
        if(x>y)
        {
            mx="ab";
            mn="ba";
            smx=x;
            smn=y;
        }
        else 
        {
            mx="ba";
            mn="ab";
            smx=y;
            smn=x;
        }
    
        stack<char> stk;
        long long ans = 0;
        for(int i=0;i<s.length();i++) 
        {
          if(stk.empty())
              stk.push(s[i]);
          else
          {
              if(s[i] == mx[1] && stk.top() == mx[0]) 
              {
                  stk.pop();
                  ans+=smx;
              }
              else 
                  stk.push(s[i]);
          }
        }
    
        string s2="";
        while(!stk.empty()) 
        {
            s2+=stk.top();
            stk.pop();
        }
        reverse(s2.begin(), s2.end());
        for(int i=0;i<s2.length();i++) 
        {
             if(stk.empty())
                stk.push(s2[i]);
          else
          {
              if(s2[i] == mn[1] && stk.top() == mn[0])
              {
                  stk.pop();
                  ans+=smn;
              }
              else
                  stk.push(s2[i]);
          }
        }
    
    return ans;
    }
};