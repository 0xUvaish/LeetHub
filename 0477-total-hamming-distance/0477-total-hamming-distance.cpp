class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int pos=0;pos<32;pos++){
            int ones=0,zeros=0;
            for(int i=0;i<nums.size();i++){
                if((nums[i]>>pos)&1){
                    ones++;
                } else {
                    zeros++;
                }
            }
            ans+=ones*zeros;
        }
        return ans;
    }
};