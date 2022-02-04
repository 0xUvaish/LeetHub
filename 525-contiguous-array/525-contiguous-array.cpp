class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
       
        unordered_map<int,int> mp;
        int total = 0;
        int target = 0;  //consider target as 0 ( variation of largest subarray sum with given target)
        int maxlen = 0;
        for(int i = 0;i<n;i++)
        {
            total += nums[i]==1?1:-1;
            
            if(total==target)
                maxlen = max(maxlen,i+1);
            else if(mp.find(total-target) != mp.end())
                maxlen = max(maxlen,i-mp[total-target]);
            else
                mp[total] = i;
        }
        return maxlen;
    }
};