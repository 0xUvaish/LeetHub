class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        unordered_map<char, int> counts;
        for(char t: tasks)
            counts[t]++;
        
        priority_queue<int> pq;
        for(auto c: counts)
            pq.push(c.second);
        
        int result=0;
        while(!pq.empty())
        {
            int time=0;
            vector<int> tmp;
            for(int i=0; i<=n; i++)
            {
                if(!pq.empty())
                {
                    tmp.push_back(pq.top() - 1);
                        pq.pop();
                        time++;
                }
            }
            
            for(auto t: tmp)
                if(t)
                    pq.push(t);
            
            result+= pq.empty() ? time: n+1;
        }
        
        return result;
    }
};