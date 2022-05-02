class Solution {
public:
    //Method 1
    //DP Solution - O(n^2) Solution
    
//         int minTaps(int n, vector<int>& ranges) 
//         {
//         vector<int> dp(n+1, n+2); //INT_MAX might lead to overflow so n+2 can work here
//         dp[0]=0;
            
//         for(int i=0; i<ranges.size(); i++)
//         {
//             for(int j = max(0, i-ranges[i]); j<=min(n, i+ranges[i]); j++)
//                 dp[j] = min(dp[j], dp[max(0, i-ranges[i])]+1);
//         }
//         return (dp[n]==n+2)?-1:dp[n];
//     }
    
    //Method 2
    //Jump Method to reach target (n index) - O(n) Solution
    int minTaps(int n, vector<int>& ranges)
    {
        for(int i=1; i<ranges.size(); i++)
        {
            if(ranges[i]==0)
                ranges[i] = i;
            
            else 
            {
                int range = max(0, i-ranges[i]);
                ranges[range] = max(i+ranges[i], ranges[range]);
            }
        }
        
        int maxIndex = 0;
        int jump = 0;
        int pos = 0;
        
        for(int i=0; i<n; i++)
        {
            if(maxIndex<i)
                return -1;
            
            maxIndex = max(maxIndex, ranges[i]);
            
            if(i==pos)
            {
                jump++;
                pos = maxIndex;
            }
        }
        
    return maxIndex>=n? jump: -1;
    }
    
    //Method 3
    //Interval Method
};