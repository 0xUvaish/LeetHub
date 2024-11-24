class Solution {
public:
    string removeDuplicates(string s, int k) {
     int n = s.size();
    
     stack<pair<char, int>> st;
     st.push({s[0], 1});
        
     int i=1;
     while(i<n)
     {
        if(st.empty() || (s[i]!=st.top().first))
            st.push({s[i], 1});
        else
            st.top().second++;
         
         
        if(st.top().second==k)
            st.pop();
         
        i++;   
     }
   
    string ans="";
    while(!st.empty())
    {
      ans.append(st.top().second, st.top().first);  //{a,2} --> add 'a' -> 2 times
      st.pop();
    }
     
    reverse(ans.begin(), ans.end());
    return ans;
        
    }
};