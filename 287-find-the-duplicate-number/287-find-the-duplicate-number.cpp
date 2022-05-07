class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //floyd cycle detection method as there can be many instances of duplicated no...so n(n+1)/2 and (n*n+1*2n+1)/6 won't work here
    int slow = nums[0];
    int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast!=slow);
        
    fast = nums[0];
        
        while(fast!=slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
 return slow;
    }
};