class Solution {
public:
    //Brute force
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans(n,0); 
        
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                if(j!=i && nums[j]<nums[i])
//                    ans[i]++;
//             }
//         }
        
//     return ans;
//     }
    
    
    
        vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums(nums.begin(), nums.end());
        sort(sorted_nums.begin(), sorted_nums.end());
        
        unordered_map<int, int> count;
        for (int i = 0; i < n; i++) {
            if (count.find(sorted_nums[i]) == count.end()) {
                count[sorted_nums[i]] = i;
            }
        }
        
        vector<int> ans;
        for (int num : nums) {
            ans.push_back(count[num]);
        }
        
        return ans;
    }
};