class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int buyPrice = prices[0];
        int sellPrice = prices[0];
        int maxProfit = sellPrice-buyPrice;
        
        for(int i=0;i!=prices.size();i++)
        {
            buyPrice = min(prices[i],buyPrice);
            // sellPrice = max(prices[i],sellPrice);
            maxProfit = max(prices[i]-buyPrice,maxProfit);    
        }
        
    return maxProfit;    
    }
};