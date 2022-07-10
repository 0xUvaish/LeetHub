class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back({0}); //cost of reaching top floor=0
        int n=cost.size();
        int prev=cost[1],prevprev=cost[0];
        int ans=0;
        for(int i=2;i<n;i++){
            ans=cost[i]+min(prev,prevprev);
            prevprev=prev;
            prev=ans;
        }
        return ans;
    }
};