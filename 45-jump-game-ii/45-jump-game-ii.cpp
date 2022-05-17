class Solution {
public:
    int jump(vector<int>& nums) 
    {
        if(nums.size()==1)
            return 0;
        
        int reach=nums[0],ind=nums[0];
        int ans=1;
        
        for(int i=1;i<nums.size()-1;i++)
        {
            reach=max(reach,nums[i]+i);

            if(ind==i)
            {
                ind=reach;
                ans++;
            }
            
        }
		return ans;
   }

};