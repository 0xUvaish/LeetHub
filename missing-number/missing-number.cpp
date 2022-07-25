class Solution {
public:
    int missingNumber(vector<int>& nums) {
     
        int n=nums.size();
        
        //Some kind of swap sort
        for(int i=0;i<n;i++)
        {
           if((nums[i]<=n-1 && nums[i]>=0) && (nums[i]!=nums[nums[i]]))   
                     // Just for eliminiating unnecessary processing here nums[i]!=nums[nums[i]-1]
           {
               swap(nums[i],nums[nums[i]]);
                i--;                 //So as to re process the same index element after swapping
           }
            
        }
                //Now checking if the index is having its corresponding element or not
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i)
                return i;
        }
        
        return n;        
    }
};