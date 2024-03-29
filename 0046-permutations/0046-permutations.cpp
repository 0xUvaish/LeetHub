class Solution {
public:
    // Swapping method
    void findperm(vector<int>& nums,int idx, vector<vector<int>> &ans)
    {
        if(idx==nums.size()) //can also be nums.size()-1 as on last index there is nothing to swap
        {
            ans.push_back(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            findperm(nums,idx+1,ans);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> ans;
        findperm(nums,0,ans);
        return ans;
    }
};