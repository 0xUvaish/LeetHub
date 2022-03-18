class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<char>s;
        for(int i=0;i<num.size();i++)
        {
            while(s.size()>0 and s.top()>num[i] and k>0)
            {
                s.pop();
                k--;
            }
            
            s.push(num[i]);
        }
        
        while(k>0)
        {
            s.pop();
            k--;
        }

        string ans=""; 
        while(!s.empty())
        {
            ans += s.top(); 
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        
         int i=0;
		/* corner case : count the leading number of zeros*/
        while(ans[i] == '0')
            i++;
		
        return (ans.substr(i) == "")? "0": ans.substr(i);
        
    }
};