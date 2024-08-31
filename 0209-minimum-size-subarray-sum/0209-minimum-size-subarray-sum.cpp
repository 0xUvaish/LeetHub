class Solution {
public:
    
    //Method 1: Sliding Window O(n)
    int minSubArrayLen(int k, vector<int>& nums) {
        //O(N)
        int sum = 0, mn = INT_MAX;
        int i = 0;
        
        for(int j=0 ; j<nums.size() ; j++)
        {
            sum += nums[j];
            
            if(sum >= k)
            {
                while(sum >= k)
                {
                    mn = min(mn, j-i+1);
                    sum = sum - nums[i];
                    i++;
                }
            }
        }
        return mn == INT_MAX ? 0 : mn;
    }
    
    //Method 2: Binary Search on answer will be O(nlogn) Doesn't need actually
};