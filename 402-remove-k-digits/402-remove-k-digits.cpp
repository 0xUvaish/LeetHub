class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string s="";
        for(int i=0;i<num.size();i++)
        {
            while(s.size()>0 and s.back()>num[i] and k>0)
            {
                s.pop_back();
                k--;
            }
            
            s += num[i];
        }
        
        while(k>0) //If all are in increasing order, then remove from the end
        {
            s.pop_back();
            k--;
        }

         int i=0;
		/* corner case : count the leading number of zeros*/
        while(s[i] == '0')
            i++;
		
        return (s.substr(i) == "")? "0": s.substr(i);
        
    }
};