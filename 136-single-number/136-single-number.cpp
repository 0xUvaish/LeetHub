class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
         int d=0;
        for(int i=0;i<nums.size();i++)
            d=d^nums[i];
        
        return d;
    }
};