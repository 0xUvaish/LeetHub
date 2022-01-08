class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
    vector<vector<int>> res;
       
        if(nums.size() < 3)
            return res;
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size()-2; i++)
        {
            
            if(i==0 || nums[i] != nums[i-1])
            {
                int low = i+1, high = nums.size()-1, sum = 0-nums[i];
                while(low < high)
                {
                    if(nums[low] + nums[high] == sum)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[low]);
                        temp.push_back(nums[high]);
                        res.push_back(temp);
                        
        //Now move low forward and high backwards, until they skip the current element(if repeated)
                        while(low<high && nums[low] == nums[low+1])
                            low++;
                        while(low<high && nums[high] == nums[high-1])
                            high--;
                        
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < sum) 
                        low++;
                    else if(nums[low] + nums[high] > sum) 
                        high--;
                }            
            }
        }
        return res; 
    }
};