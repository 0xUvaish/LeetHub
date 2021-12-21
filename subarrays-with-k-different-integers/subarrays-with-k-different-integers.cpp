class Solution {
public:
    int solve(vector<int>& nums, int k) {
        unordered_map<int, int> uMap;
        int size = 0;
        int slow = 0, fast = 0;
        uMap[nums[fast++]]++;
        size++;
        
        int count = 0;
        
        while(slow < nums.size()){
            if((slow == fast || size < k) && (fast < nums.size())){
                if(uMap.find(nums[fast]) == uMap.end() || uMap[nums[fast]] == 0)
                    size++;
                uMap[nums[fast++]]++;
            }
            else{
                if(size == k){
                    count += nums.size() - fast + 1;
                }
                uMap[nums[slow]]--;
                if(uMap[nums[slow]] == 0)
                    size--;
                slow++;
            }
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k+1);
    }
};