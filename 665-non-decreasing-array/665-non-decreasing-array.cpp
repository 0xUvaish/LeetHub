class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
        int cnt=0;
        int n = nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]>nums[i+1])   //violation condition - decreasing
            {
                if(cnt==1) 
                    return false;
                cnt++;
                
                if(i==0 || nums[i+1]>=nums[i-1])
                    nums[i] = nums[i+1];  //first possiblity :-> if next element greater than or equal to previous element then update middle element to its next element
                else
                    nums[i+1] = nums[i];  //else update next element to middle one  - Diagram will clear it
            }
        }
        return true; 
    }
};