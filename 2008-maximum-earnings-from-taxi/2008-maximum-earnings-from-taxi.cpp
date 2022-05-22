class Solution {
public:
    long long dp[(int)1e5];
    int nextPosition(vector<vector<int>>& rides, int val, int idx){
        int l = idx;
        int h = rides.size() - 1;
        int pos = - 1;
        int mid;
        
        while(l <= h)
        {
            mid = l + (h - l)/2;
            if(rides[mid][0] >= val)
            {
                pos = mid;
                h = mid - 1;
            }
            else 
                l = mid + 1;
        }
          return pos;
          
    }
    
    long long solve(vector<vector<int>>& rides, int idx){
       
       if(idx >= rides.size()) 
           return 0;
       
       if(dp[idx] != -1) 
           return dp[idx];
        
         // option 1 is to not consider this passenger
      long long op1 = solve(rides, idx + 1);
        
        // option 2 is to consider this passenger
      int nextPos = nextPosition(rides, rides[idx][1], idx);
      long long op2 = rides[idx][1] - rides[idx][0] + rides[idx][2] + solve(rides,nextPos);
        
      return dp[idx] = max(op1,op2);
    }
    
    
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) 
    {
        sort(rides.begin(),rides.end());
        memset(dp,-1,sizeof(dp));
        return solve(rides,0);
    }
};