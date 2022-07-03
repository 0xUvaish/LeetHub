class Solution {
public:
    //M1: LIS Variation
    int wiggleMaxLength(vector<int>& nums) {
          int n=nums.size();
          
        if(n==1)
            return 1;
		
		//dp[n][2] declared, dp[x][0] will store local maxima
		//dp[x][1] will store local minima
        vector<vector<int>>dp(n,vector<int>(2,1));
        
        int ma=INT_MIN;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j] and dp[i][0]<dp[j][1]+1)
                    dp[i][0]=dp[j][1]+1;
				
                else if(nums[i]<nums[j] and dp[i][1]<dp[j][0]+1)
                    dp[i][1]=dp[j][0]+1;
            }
            ma=max(ma,max(dp[i][0],dp[i][1]));
        }
        return ma;
    }
    
    //M2: O(n) Sol - NOT LIS /But Greedy
//     int wiggleMaxLength(vector<int> nums)
//     {
//         int n=nums.size();
//           if(n==1)
//             return 1;
        
//         vector<int> v;
//         bool incr=false;
//         bool decr=false;

//             for(int i=0;i<n-1;i++)
//             {
//                if((decr==false and (nums[i]>nums[i+1])))
//                 {
//                  v.push_back(nums[i]);
//                  incr=false;
//                  decr=true;
//                 }
//               else if((incr==false and (nums[i]<nums[i+1])))
//                {
//                v.push_back(nums[i]);
//                 decr=false;
//                 incr=true;
//               }
//             }

//           return v.size()+1;
//     }
};