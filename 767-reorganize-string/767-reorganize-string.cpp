class Solution {
public:
    string reorganizeString(string s) 
    {
        map<char, int> m;
        for(auto &i : s)
            m[i]++;
            
        priority_queue<pair<int, char>> pq;
        for (auto &ele : m)
            pq.push(make_pair(ele.second, ele.first));
            
        string ans="";
        
        while(pq.size()>1) 
        {
            char mostFrequent = pq.top().second;
            pq.pop();
            char nextFrequent = pq.top().second;
            pq.pop();
            
            ans += mostFrequent;
            ans += nextFrequent;
            
            if (m[mostFrequent]>1) 
            {
                m[mostFrequent]--;
                pq.push(make_pair(m[mostFrequent], mostFrequent));
            }
            if (m[nextFrequent]>1) 
            {
                m[nextFrequent]--;
                pq.push(make_pair(m[nextFrequent], nextFrequent));
            }
        }
        
        if(pq.size()) 
        {
            char lastChar = pq.top().second;
            if (m[lastChar]>1)
                return "";
            else
                ans += lastChar;
        }
        
        return ans;
    }
};