class Solution {
public:
    int wiggleMaxLength(vector<int> nums)
    {
        int n=nums.size();
          if(n==1)
            return 1;
        
        vector<int> v;
        bool pos=false;
        bool neg=false;

            for(int i=0;i<n-1;i++)
            {
               if((neg==false and (nums[i+1]<nums[i])))
                {
                 v.push_back(nums[i]);
                 pos=false;
                 neg=true;
                }
              else if((pos==false and (nums[i+1]>nums[i])))
               {
               v.push_back(nums[i]);
                neg=false;
                pos=true;
              }
            }
        
          nums=v;
          return v.size()+1;
    }
};