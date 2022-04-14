class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital)
    {
        int n=profits.size();
        
        priority_queue<int>profit_pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>capital_pq;
        
        
        for(int i=0;i<n;i++)
            capital_pq.push({capital[i],i});       //Insert all Capitals with their indices
        
        for(int i=0;i<k;i++)
        {
            while(!capital_pq.empty() && capital_pq.top().first<=w)
            { 
                profit_pq.push(profits[capital_pq.top().second]);
                capital_pq.pop();
            }
            
            if(profit_pq.empty())
                return w;               //if we can't buy any more profit 
            
            w += profit_pq.top();      //add max profit
            profit_pq.pop();          // remove used profit
        }
        return w;
    }
};