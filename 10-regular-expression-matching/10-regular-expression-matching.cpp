class Solution {
public:
    //Method 1: Direct STL 
	// bool isMatch(string s, string p) 
	// {
	// regex obj(p);
	// if(regex_match(s, obj))
	// 	return true;
	// else
	// 	return false;
	// }
    
    //Method 2: 
    //Call 1: Don't use * (i,j+2)
    //Call 2: Use * (i+1,j)
    //Call 3: No * present (i+1,j+1)
    
    bool dp(int i, int j, string s, string p, vector<vector<int>> &memo)
    {
        
        if(j==p.length())
            return (i == s.length());
        
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        bool ans;

            bool match =  (i<s.length() && (p[j]==s[i] || p[j]=='.'));
            
            if(j+1<p.length() && p[j+1]=='*') //* Present
                ans = (dp(i, j+2, s, p, memo)|| (match && dp(i+1, j, s, p, memo)));
            else
                ans = (match && dp(i+1, j+1, s, p, memo));  // * Not present
        
        memo[i][j] = ans?1:0;
        return ans;
    }
    
    bool isMatch(string s, string p) 
    {
        vector<vector<int>> memo(s.length()+1, vector<int>(p.length()+1, -1));
        return dp(0, 0, s, p, memo);
    }
};