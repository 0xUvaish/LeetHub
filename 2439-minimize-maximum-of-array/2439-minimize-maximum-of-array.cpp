class Solution {
public:
    bool isPossible(vector<int> &nums, int k){
        long long int excessAvailable = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > k){
               if(nums[i] - k > excessAvailable){
                   return false;
               }
                excessAvailable -= (nums[i] - k);
            }
 
          else if(nums[i] <= k)
                excessAvailable += (k - nums[i]);
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, r = *max_element(nums.begin(), nums.end()), ans;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(isPossible(nums, mid)){
                ans = mid;
                r = mid-1;
            }
            else 
                l = mid + 1;
        }
        return ans;
    }
};