class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        
        int l=0, r=nums.size()-1, mid, mid2;
        
        while(l < r)
        {
            mid = l+(r-l)/2;
            
            mid2 = (mid%2 == 0) ? mid+1 : mid-1;
            
            if(nums[mid]==nums[mid2])
                l = mid+1;
            
            else r = mid;
        }
        return nums[l];
    }
};