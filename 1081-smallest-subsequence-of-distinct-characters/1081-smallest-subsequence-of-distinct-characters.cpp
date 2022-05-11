class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> freq(123,0);
        vector<bool> include(123,false);
        
        for(auto &c:s)
            freq[c]++;
    
        string res = "";
    
        for(auto &c:s)
        {
            freq[c]--;
            if(include[c])
                continue;
            
            while(!res.empty() && res.back()>c && freq[res.back()]!=0)
            {
                include[res.back()]=false;
                res.pop_back();
            }
            
            include[c] = true;
            res += c;
        }
    
        return res;
    }
};