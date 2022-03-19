class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
               int ans=0,cnt=0;
        for(auto x: nums)
        {
            if(x==1)
                cnt++;
            else
                cnt=0;
            
        ans = max(ans, cnt);
        }
        
    return ans;
    }
};