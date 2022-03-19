class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.length();
        unordered_set <char> m;
        int i=0,j=0,ans=0;
        while(j < n)
        {
            if(m.find(s[j])==m.end())
            {
                m.insert(s[j]);
                ans=max(ans, j-i+1);
            }
            
            else
            {
                while(m.find(s[j])!=m.end() && i<n)
                {
                    m.erase(s[i]);
                    i++;
                }
                
                m.insert(s[j]);
            }
            
            j++;
        }
        
    return ans;  
    }
};