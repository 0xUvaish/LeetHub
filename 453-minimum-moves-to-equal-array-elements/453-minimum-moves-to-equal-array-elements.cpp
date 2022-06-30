class Solution {
public:
    //M1: Sorting TC O(nlogn)
    int minMoves(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
            ans+=nums[i]-nums[0];
        return ans;
    }
};