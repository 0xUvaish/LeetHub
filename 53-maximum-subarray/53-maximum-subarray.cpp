class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int me=0,maxii=INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            me+=nums[i];
            if(me<nums[i])
                me=nums[i];
            
            if(me>maxii)
                maxii = me;
        }
        
        return maxii;
    }
};