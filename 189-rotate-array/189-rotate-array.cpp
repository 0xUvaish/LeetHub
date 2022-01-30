class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k = k % nums.size();    
        if(k > 0)
        {
            reverse(nums.begin(), nums.end()-k);
            reverse(nums.end() - k, nums.end());
            reverse(nums.begin(), nums.end());
        }
    }
};