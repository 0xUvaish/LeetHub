class Solution {
public:
    
string removeDuplicateLetters(string s) {
        vector<int> dict(123,0);
        vector<bool> vis(123,false);
        
        for(auto &c:s)
            dict[c]++;
    
        string res = "";
    
        for(auto &c:s)
        {
            dict[c]--;
            if(vis[c])
                continue;
            
            while(!res.empty() && res.back()>c && dict[res.back()]!=0)
            {
                vis[res.back()]=false;
                res.pop_back();
            }
            
            vis[c] = true;
            res += c;
        }
    
        return res;
    }
};