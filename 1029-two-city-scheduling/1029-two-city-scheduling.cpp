class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
      int n = costs.size();
        int minCost=0;
        vector<int> diffBA(n);
            for(int i=0;i<n;i++)
            {
                minCost += costs[i][0];
                diffBA[i]= (costs[i][1]-costs[i][0]);
            }
        
        sort(diffBA.begin(), diffBA.end());
        
        for(int i=0;i<n/2;i++)
            minCost += diffBA[i];
        
    return minCost;
    }
};