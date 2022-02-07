class Solution {
public:
    char findTheDifference(string s, string t) {
     unordered_map<char,int> mp;
        for(auto c: t)
           mp[c]++;
        
        for(auto c: s)
            mp[c]--;
        
        for(auto a: mp)
            if(a.second)
                return a.first;
        
       return 'a'; 
    }
};