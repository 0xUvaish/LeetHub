class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size() ;

        unordered_set<string> s ; 

        for(int i=0 ; i<n ; i++)
        {
            s.insert(ideas[i]);
        }

        vector<vector<int>> dp(26,vector<int>(26,0)); 

        for(int i=0 ; i<n ; i++)
        {
            string idea = ideas[i] ;

            char old = idea[0] ;

            for(char newchar='a' ; newchar<='z' ; newchar++)
            {
                idea[0]=newchar;

                if(s.count(idea)==0)
                {
                    dp[old-'a'][newchar-'a']++;
                }
            }
        }
           
            long long ans =0 ; 
            for(int i=0 ; i<26 ; i++)
            {
                for(int j=0 ; j<26 ; j++)
                {
                    ans+= (long long)dp[i][j]*(long long)dp[j][i];
                }
            }

            return ans;
    }
};