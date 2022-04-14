class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
     
        int n=nums.size();
        
        //Some kind of swap sort
        for(int i=0;i<n;i++)
        {
           if((nums[i]<=n && nums[i]>=1) && (nums[i]!=nums[nums[i]-1]))
           {
               swap(nums[i],nums[nums[i]-1]);
                i--; //So as to re process the same index element after swapping
           }
            
        }
                //Now checking if the index is having its corresponding element or not
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        
        return n+1;
    }
};
