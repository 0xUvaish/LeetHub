class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) 
    {
        vector<int> ans;
        int total=0;
        sort(nums.begin(),nums.end(),greater<int> ());
        
        for(int i=0;i<nums.size();i++) 
            total +=nums[i];
        
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum +=nums[i];
            ans.push_back(nums[i]);
            if(sum > total-sum)
                return ans;
        }
        return ans;
    }

};