class Solution {
public:
int search(vector<int>& nums,int target,bool firstStartIndex)
{
    int ans=-1;
    int lb = 0, ub = nums.size()-1, m;
    
    while (lb <= ub)
    {
        m = lb + (ub - lb) / 2;
        if (nums[m] > target)
            ub = m - 1;
        else if (nums[m] < target)
            lb = m + 1;
        else
        {
            ans=m;                       
            if(firstStartIndex==true)   //only change from Binary Search
                ub=m-1;
            else
                lb=m+1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans(2);
        ans[0]=-1; ans[1]=-1;
        
        ans[0]=search(nums,target,true);
        ans[1]=search(nums,target,false);
        
        return ans;
    }
};