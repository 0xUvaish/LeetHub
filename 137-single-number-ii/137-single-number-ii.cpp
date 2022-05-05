class Solution {
public:
    
    //Method 1: Sorting + Iterating --> O(nlogn) TC, O(1) Space
    //Method 2: Using Frequency Map --> O(n) TC, O(n) Space
    //Method 3: Bit Manipulation --> O(n) TC, O(1) Space
    
    int singleNumber(vector<int>& nums) 
    {
        int ans=0;
        for(int i=0; i<=31; i++)
        {
            int cnt=0;
            for(auto x: nums)
            {
                if(x&(1<<i))
                 cnt++;
            }
            
            if(cnt%3)
                ans |= (1<<i);
        }
        
    return ans;
    }
};