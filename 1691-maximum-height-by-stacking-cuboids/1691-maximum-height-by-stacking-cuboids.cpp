class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {

        for(auto &x:cuboids)
            sort(x.begin(),x.end());
        
        sort(cuboids.begin(),cuboids.end());
        
        int n=cuboids.size();
        vector<int> dp(n,0);
        
    for (int i=0;i<n;i++)
    {
        dp[i]=cuboids[i][2];          //Max Height of Curr Cuboid
        for (int j=0;j<i;j++)
        {
        if(cuboids[j][1]<=cuboids[i][1] && cuboids[j][2]<=cuboids[i][2])//Not checking for cuboids[j][0] 
            dp[i]=max(dp[i],dp[j]+cuboids[i][2]);        //cuboids[i][0] because already sorted
        }
    }
        return *max_element(dp.begin(),dp.end());
    }
};