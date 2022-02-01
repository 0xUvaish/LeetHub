class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int buyPrice = prices[0];
        int maxProfit = prices[0]-buyPrice;
        
        for(int i=0;i<prices.size();i++)
        {
            buyPrice = min(prices[i],buyPrice);
            maxProfit = max(prices[i]-buyPrice,maxProfit);    
        }
        
    return maxProfit;    
    }
};