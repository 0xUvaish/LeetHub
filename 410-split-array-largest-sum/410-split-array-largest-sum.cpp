class Solution {
public:
    bool help(vector<int>& nums, int mid, int m)
    {
        int k=1,sum=0;
        for(auto y: nums)
        {
            sum += y;
            if(sum>mid)
            {
                k++;
                sum=y;
            }
        }
        
    return (k<=m);
    }
    
    
    int splitArray(vector<int>& nums, int m) 
    {
        int low = *max_element(nums.begin(), nums.end());
        int sum, ans;
        
        for(auto x: nums)
            sum += x;
        
        int high = sum;
        ans = high;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(help(nums, mid, m))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
    return ans;
    }
};