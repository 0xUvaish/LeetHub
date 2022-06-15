class Solution {
public:
	bool checkPossible(string& s1,string& s2){
		if(s1.size()!=s2.size()+1)
            return false;
        
		int f=0, s=0;
		while(f<s1.size())
        {
			if(s<s2.size() and s1[f]==s2[s])
            {
				f++;
				s++;
			}
			else
            {
				f++;
			}
		}
        
		if(f==s1.size() and s==s2.size())
            return true;
		return false;
	}

	static bool comp(string& s1, string& s2){
		return s1.size()<s2.size();
	}

	int longestStrChain(vector<string>& words) {
	  sort(words.begin(), words.end(), comp);
		int n= words.size();
		vector<int>dp(n,1);
		int maxi=1;
		for(int i=0;i<n;i++){
			for(int prev=0;prev<i;prev++){
				if(checkPossible(words[i],words[prev]) and dp[i]<1+dp[prev]){
					dp[i]= 1+dp[prev];
				}
			}
			maxi= max(maxi,dp[i]);
		}
		return maxi;
	}
};