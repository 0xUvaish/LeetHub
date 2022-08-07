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
    
//     int minTaps(int n, vector<int>& ranges)
//     {
//         for(int i=1; i<ranges.size(); i++)
//         {
//             if(ranges[i]==0)
//                 ranges[i] = i;
            
//             else 
//             {
//                 int range = max(0, i-ranges[i]);
//                 ranges[range] = max(i+ranges[i], ranges[range]);
//             }
//         }
        
//         int maxIndex = 0;
//         int jump = 0;
//         int pos = 0;
        
//         for(int i=0; i<n; i++)
//         {
//             if(maxIndex<i)
//                 return -1;
            
//             maxIndex = max(maxIndex, ranges[i]);
            
//             if(i==pos)
//             {
//                 jump++;
//                 pos = maxIndex;
//             }
//         }
        
//     return maxIndex>=n? jump: -1;
//     }
    
    //Method 3
    //Interval Method - O(n) Solution
    
    int minTaps(int n, vector<int>& ranges) 
    {
        vector <vector<int>> intervals;
        for (int i = 0; i < ranges.size(); i++)
        {
            vector<int> inter{i - ranges[i], i + ranges[i]};
            intervals.push_back(inter);
        }
        
        sort(intervals.begin(), intervals.end(), [](auto &p, auto &q){
            return (p[0] < q[0]);
        });
        
        int count = 0, start_time = 0, end_time = 0;
        
        int i=0;
        while (end_time < n) 
        {
            while(i<intervals.size() && start_time >= intervals[i][0])
            {
                end_time = max(end_time, intervals[i][1]);
                i++;
            }
            
            if (start_time == end_time)  //end time did not exceed start time 
                return -1;
            
            count++;
            start_time = end_time;
        }
        
        return count;
    }
    
    
    
};