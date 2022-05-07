class Solution {
public:
    
    bool wordBreak(string &s,int n,int i,unordered_set<string> &dict, vector<int> &dp)
    {
        if(i==n)
            return 1;
        
        if(dp[i]!=-1) 
            return dp[i]==1;          

            string temp="";
            for(int k=i;k<n;k++)
            {
                temp += s[k];
                if(dict.find(temp)!=dict.end())
                    if(wordBreak(s,n,k+1,dict,dp))
                        return dp[i]=1;
            }
            
    return dp[i]=0;
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n=s.length();
        vector<int> dp(n+1,-1);
        
        return wordBreak(s,n,0,dict,dp);
    }
};