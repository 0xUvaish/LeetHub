class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        priority_queue<int> pq(piles.begin(), piles.end());
    
        for(int i = 0;i<k;i++)
        {             
            int remtotal = pq.top();
            pq.pop();
            int rem = floor(remtotal/2);    
            pq.push(remtotal-rem);
        }
    
        int ans = 0;
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        

        return ans;
    }
};