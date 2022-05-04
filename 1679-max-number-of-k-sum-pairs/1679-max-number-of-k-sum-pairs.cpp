class Solution {
public:
int maxOperations(vector<int>& nums, int k)
{
        unordered_map<int, int> mp;
        int n = nums.size(), required, ans = 0;
        
        mp[nums[0]]++;
        
        for(int i=1; i<n; i++)
        {
            required = k - nums[i];
            if(mp[required] > 0)
            {
                mp[required]--;
                ans++;
            }
            else
            {
                mp[nums[i]]++;
            }
        }
        return ans;
    }
};