class Solution {
public:
    int dp[101][201];
    int mod = 1e9+7;
    int rec(vector<int> &locations, int idx, int finish, int fuel){
      if(fuel<0) return 0; //Exit case.
      long long ans = 0;
      if(dp[idx][fuel]!=-1) return dp[idx][fuel]%mod;
      // Now checking all the possible path.
      for(int i = 0;i<locations.size(); i++){
        if(i==idx) continue;
        ans = (ans%mod +  rec(locations, i, finish, fuel-abs(locations[i]-locations[idx]))%mod)%mod;
      }

      //During return we have to is idx ==  finish.
      if(idx==finish) return dp[idx][fuel] = (1 +  ans)%mod;
      return dp[idx][fuel] = ans%mod;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
       memset(dp, -1, sizeof(dp));
       return rec(locations, start, finish, fuel); 
    }
};