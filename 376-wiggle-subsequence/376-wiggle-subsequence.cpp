class Solution {
public:
    int wiggleMaxLength(vector<int> nums)
    {
        int n=nums.size();
          if(n==1)
            return 1;
        
        vector<int> v;
        bool incr=false;
        bool decr=false;

            for(int i=0;i<n-1;i++)
            {
               if((decr==false and (nums[i]>nums[i+1])))
                {
                 v.push_back(nums[i]);
                 incr=false;
                 decr=true;
                }
              else if((incr==false and (nums[i]<nums[i+1])))
               {
               v.push_back(nums[i]);
                decr=false;
                incr=true;
              }
            }

          return v.size()+1;
    }
};