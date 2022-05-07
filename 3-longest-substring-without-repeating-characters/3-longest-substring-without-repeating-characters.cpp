class Solution {
public:
    //Method 2: Aditya Varma Playlist
    int lengthOfLongestSubstring(string s) 
    {
        int i=0;
        int j=0;
        int n = s.size();
        int ans=INT_MIN;
        map<char,int>mp;
        if(s.empty())
            return 0;

            while(j<n)
            {
                mp[s[j]]++; 
                
                if(mp.size()==j-i+1)
                {
                    ans=max(ans,j-i+1);
                    j++;
                }
                
                else if(mp.size()< j-i+1)
                {
                    while(mp.size() < j-i+1)
                    {
                        mp[s[i]]--; 
                        if(mp[s[i]]==0)
                            mp.erase(s[i]);
                       i++;
                    }
                    
                    j++;
                }
            }
        
    return ans;
    }
};