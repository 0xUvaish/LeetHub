class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if(nums.size()==1)
            return 0;
        
        int futureReach=nums[0],currReach=nums[0];
        int ans=1;
        
        for(int i=1;i<nums.size()-1;i++)
        {
            futureReach=max(futureReach,nums[i]+i);

            if(currReach==i)
            {
                currReach=futureReach;
                ans++;
            }
            
        }
		return ans;
   }

};