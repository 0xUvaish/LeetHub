class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int t1_sum, t2_sum, arr_sum, max_sum, min_sum;
        t1_sum = t2_sum = arr_sum = max_sum = min_sum = nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            t1_sum = max(nums[i], t1_sum+nums[i]);
            max_sum = max(max_sum, t1_sum);
            
            t2_sum = min(nums[i], t2_sum+nums[i]);
            min_sum = min(min_sum, t2_sum);
            
            arr_sum += nums[i];
        }
    return max_sum > 0 ? max(max_sum, arr_sum-min_sum) : max_sum;
    }
};