struct Compare 
{
    bool operator()(pair<int, string> &str1, pair<int, string> &str2) 
    {
        if(str1.first < str2.first)
            return true;
        
        if(str1.first > str2.first)
            return false;
        
        if(str1.second.compare(str2.second) > 0)
            return true;
        
        return false;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        vector<string> result;
        unordered_map<string, int> hashmap;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> heap;
        
        for(auto &x: words)
            hashmap[x]++;
        
        for(auto &x: hashmap)
            heap.push({x.second, x.first});
        
        while(k--) 
        {
            result.push_back(heap.top().second);
            heap.pop();
        }
        
        return result;
    }
};