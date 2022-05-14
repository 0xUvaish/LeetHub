class Solution {
public:
    //Method 1: O(26*n) Calculate max freq ecery time without taking extra variable
    
    //Method 2: O(n) TC
    int characterReplacement(string s, int k) {
        
        int i=0;
        int maxFreq=0;
        vector<int>v(26,0);
        
        int ans=INT_MIN;
        
       for(int j=0;j<s.size();j++)
        {
            v[s[j]-'A']++;
            maxFreq = max(maxFreq, v[s[j]-'A']);
           
            while(j-i+1-maxFreq>k)
            {
                v[s[i]-'A']--;
                i++;
            }
           
            ans=max(ans,j-i+1);
        }
        
        return ans;
    }
};