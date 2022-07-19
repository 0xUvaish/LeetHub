class Solution {
public:
    //Sol1: DP
//     int lengthOfLIS(vector<int>& nums) {
        
//        int n = nums.size();
//        int lis[n];
//        int maxLIS = 1;
//        lis[0] = 1;
        
//        for(int i=1;i<n;i++)
//        {
//            lis[i] = 1;
//            for(int j=0;j<i;j++)
//            {
//                if(nums[j]<nums[i])
//                {
//                    lis[i] = max(lis[i],lis[j]+1);
//                    maxLIS = max(maxLIS, lis[i]);
//                }
//            }
//        }    

//         return maxLIS;
//     }
    
    
    //Sol2: Binary Search - Striver
    int findCeil(vector<int> &tail, int x)
    {
        int k = tail.size();
        int l = 0, r = k - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (tail[m] >= x)
                r = m;
            else
                l = m + 1;
        }
        return r;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> tail(1, nums[0]);
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > tail.back())
                tail.push_back(nums[i]);
            else
                tail[findCeil(tail, nums[i])] = nums[i];
        }
        return tail.size();
    }
};