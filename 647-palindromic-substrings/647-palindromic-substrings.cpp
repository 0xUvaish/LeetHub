class Solution {
public:
int help(int st, int e, string &s)
{
	int val = 0, n = s.size()-1;
	while(st >= 0 && e <= n && s[st--] == s[e++])
		val++;
    
	return val;
}

int countSubstrings(string s) 
{
	int n = s.size(), ans = 0;
	for(int i = 0; i < n; i++) 
    {
		ans += help(i, i, s);
		if(i < n-1 && s[i] == s[i+1])
			ans += help(i, i+1, s);
	}
    
	return ans;
}
    
};