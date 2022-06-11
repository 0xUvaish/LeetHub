class Solution {
public:
    int minOperations(vector<int>& nums, int x) 
    {
    int left = 0 , right = 0 , maxlen = -1 , n = nums.size() , total = 0;
        for(int i : nums)
            total += i;
        
        int curr = 0;
        int target=total-x;
        while(right<n)
        {
            curr += nums[right];
            
            while(curr > target && left<=right) 
            {
                curr -= nums[left];
                left++;
            }
            
            if(curr == target)
                maxlen = max(maxlen , right-left+1);
        right++;
        }
        
return maxlen != -1 ? n-maxlen : -1;
    }
};