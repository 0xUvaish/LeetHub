class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        unordered_set<int> st;
        int j=0, curr=0, res=0;
        for(int i=0; i<nums.size(); i++){
            curr+=nums[i];
            while(st.find(nums[i])!=st.end())
            {
                curr-=nums[j];
                st.erase(nums[j]);
                j++;
            }
            res = max(res, curr);
            st.insert(nums[i]);
        }
        return res;
    }
};