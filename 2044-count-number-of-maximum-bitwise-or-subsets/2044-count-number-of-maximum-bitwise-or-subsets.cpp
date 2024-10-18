class Solution {
public:
    int countSubsetsTarget(int idx,int curr,int const &target,vector<int> const &nums){
        if(idx == nums.size()){
            if(target == curr)
                return 1;
            return 0;
        }
        return (countSubsetsTarget(idx+1,(curr | nums[idx]),target,nums) + countSubsetsTarget(idx+1,curr,target,nums));
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for(auto &x:nums)
            target |= x;
        return countSubsetsTarget(0,0,target,nums);
    }
};