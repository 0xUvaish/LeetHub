class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i : q) {
            int cursum = 0, count = 0;
            while (count < nums.size() and cursum + nums[count] <= i) {
                cursum += nums[count];
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};