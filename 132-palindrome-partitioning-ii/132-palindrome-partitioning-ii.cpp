class Solution {    
public:
    vector<vector<int>> pal;
    vector<vector<int>> t;
    
   bool isPalindrome(string& s, int i, int j)
   {
		if(i>=j) 
            return true;
       
		if(pal[i][j]!=-1) 
            return pal[i][j];
       
		if(s[i]==s[j])
            return pal[i][j] = isPalindrome(s, i + 1, j - 1);
       
		return pal[i][j] = false;
	}
    
    int solve(string &s, int i, int j)
    {
        if(i>=j) 
            return t[i][j] = 0;
        
        if(t[i][j] != -1) 
            return t[i][j];
        
        if(isPalindrome(s,i,j)) 
            return t[i][j] = 0;
        
        int res = INT_MAX;
        
        for(int k=i; k<=j-1; k++)
        {
            if(isPalindrome(s,i,k)) res = min(res, 1 + solve(s,k+1,j));
        }
        
        return t[i][j] = res;
    }
    
    int minCut(string s) 
    {
        int n= s.size();
        int i=0, j=n-1;
        
		pal.resize(n,vector<int> (n,-1));
        t.resize(n,vector<int> (n,-1));
        
        return solve(s,i,j);
    }
};