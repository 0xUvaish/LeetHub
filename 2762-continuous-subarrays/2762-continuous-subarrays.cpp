class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> ms;
        long long ans = 0, j = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            ms.insert(nums[i]);
            while (!ms.empty() and *ms.rbegin() - *ms.begin() > 2)
                ms.erase(ms.find(nums[j++]));
            ans += i - j + 1;
        }
        return ans;
    }
};