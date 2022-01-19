class Solution {
public:
    
    static bool compare(pair<char,int> a, pair<char,int> b) {
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        
        map<char,int> mp;
        
        for(char c: s) 
            mp[c]++;
        
        vector<pair<char,int>> vec;
        
        for(auto x: mp)
            vec.push_back({x.first, x.second});
        
        sort(vec.begin(), vec.end(), compare);
        
        s = "";
        
        for(auto x: vec)
            while(x.second--)
                s += x.first;    
        
        return s;
    }
};