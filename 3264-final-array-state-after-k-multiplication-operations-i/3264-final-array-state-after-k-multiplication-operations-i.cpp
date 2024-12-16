class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k != 0) {
            auto it = min_element(nums.begin(), nums.end());
            *it *= multiplier;
            k--;
        }
        return nums;
    }
};