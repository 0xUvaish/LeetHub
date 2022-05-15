class Solution {
public:
    unordered_set<string>st;
    vector<vector<int>>dp;
    bool solve(string &s,int i,int f)
    {
        if(i==s.size())
            return f==2;
        
        if(dp[i][f]!=-1)
            return dp[i][f];
        
        bool ans=false;
        string t="";
        int val;
        
        for(int j=i;j<s.size();j++)
        {
            t+=s[j];
            val=f;
            
            if(st.find(t)!=st.end())
            {
                val++;
                if(val>2)
                    val=2;
                
                ans=ans|| solve(s,j+1,val);
                
                if(ans)
                    break;
            }
        }
        return dp[i][f]=ans;
    }
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        for(auto s:words)
            st.insert(s);
        
        vector<string>ans;
        for(auto s:words)
        {
            dp.clear();
            dp.resize(s.size(),vector<int>(3,-1));
            
            if(solve(s,0,0))
                ans.push_back(s);
        }
        
        return ans;
    }
};