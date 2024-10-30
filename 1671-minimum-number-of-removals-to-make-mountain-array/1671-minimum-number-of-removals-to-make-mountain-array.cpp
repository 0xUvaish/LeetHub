class Solution {
public:
    // https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/discuss/951981/C%2B%2B-Easy-O(N2)-solution-using-LIS-twice
int minimumMountainRemovals(vector<int>& nums) {
    vector<int> dpleft(nums.size(), 1);
    vector<int> dpright(nums.size(), 1);
    for(int i=1; i<nums.size(); i++) {
        for(int j=0; j<i; j++) {
            if(nums[i]>nums[j]) {
                dpleft[i] = max(dpleft[i], dpleft[j]+1);
            }
        }
    }
    //coming from right
    for(int i=nums.size()-2; i>=0; i--) {
        for(int j=nums.size()-1; j>i; j--) {
            if(nums[i]>nums[j]) {
                dpright[i] = max(dpright[i], dpright[j]+1);
            }
        }
    }
    //calculate the longest
    int longest = 0;
    //conside i the middle
    for(int i=1; i<nums.size()-1; i++) {
        if(dpleft[i]>1 && dpright[i]>1) {
            int ans = dpleft[i]+dpright[i]-1;
            longest = max(longest, ans);
        }
    }
    return nums.size()-longest;
}
};