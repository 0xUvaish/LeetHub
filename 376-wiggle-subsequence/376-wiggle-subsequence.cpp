class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
       if(nums.size()<2) 
           return 1;
        
        int ans=1;
        for(int i=1, mul=0; i<nums.size();i++)
        {
            int diff = nums[i]-nums[i-1];
            if(diff != 0)
            {
                if(mul*diff <= 0) 
                    ans++;
                mul = diff;
            }
        }
        return ans;  
    }
};