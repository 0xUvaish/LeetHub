class Solution {
public:
    //M1: Sorting TC O(nlogn)
    // int minMoves(vector<int>& nums) {
    //     int ans=0;
    //     int n=nums.size();
    //     sort(nums.begin(),nums.end());
    //     for(int i=1;i<n;i++)
    //         ans+=nums[i]-nums[0];
    //     return ans;
    // }
    
    //M2: Find Min directly O(n)
        int minMoves(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        int mn=(1e9+8),idx=0;
        for(int i=0;i<n;i++){
            if(mn>nums[i]){
                mn=nums[i];
                idx=i;
            }
        }
        for(int i=0;i<n;i++)
            if(i!=idx)
                ans+=(nums[i]-mn);
        return ans;
    }
};