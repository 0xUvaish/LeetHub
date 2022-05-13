class Solution {
public:
    int rob(vector<int>& nums) {
        
        for (int i = 1; i < nums.size(); i++)
            nums[i] = max(nums[i - 1], (i != 1 ? nums[i - 2] : 0) + nums[i]);
        
    return nums[nums.size() - 1];  
    }
};