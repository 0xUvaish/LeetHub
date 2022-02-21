class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
 
        int res1=INT_MIN;
        int cnt1=0;
        int res2=INT_MIN;
        int cnt2=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==res1)
                cnt1++;
            
            else if(nums[i]==res2)
                cnt2++;
            
            else{
                if(cnt1==0)
                {
                    res1=nums[i];
                    cnt1=1;
                }
                else if(cnt2==0)
                {
                    res2=nums[i];
                    cnt2=1;
                }
                else
                {
                    cnt1--;
                    cnt2--;
                }
            }
        }

        cnt1=0;cnt2=0;
        
        for(int i:nums)
        {
            if(res1==i)
                cnt1++;
            else if(res2==i)
                cnt2++;
        }
        
        vector<int> res;
        if(cnt1>n/3)
            res.push_back(res1);
        if(cnt2>n/3)
            res.push_back(res2);
        
        return res;
    }
};