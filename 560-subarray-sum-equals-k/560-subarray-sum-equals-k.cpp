class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
       unordered_map<int, int> mp;
        mp[0]=1;
        int ans = 0, sum = 0;
        
        for (auto n: nums)
        {
            sum += n;
            
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};