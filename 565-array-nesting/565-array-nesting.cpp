class Solution {
public:
    //Method 3: O(N) TC, O(1) SC
    int arrayNesting(vector<int>& nums) 
    {
       
        int res =0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != -1)          //Not visited yet
            {
                int start = nums[i], count=0;
                while(nums[start] != -1)
                {
                    int tmp = start;
                    
                    start = nums[start];
                    count++;
                    
                    nums[tmp] = -1;
                }
                
                res = max(res, count);
            }
        }
        
    return res;
    }
    
};