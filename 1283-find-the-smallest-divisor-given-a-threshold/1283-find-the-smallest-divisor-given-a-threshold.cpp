class Solution {
public:
    int help(vector<int>& nums, int k)
    {
        int sum = 0;
        for(auto x: nums)
        {
            sum += x/k;
            
            if(x%k != 0)
                sum++;
        }
    return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = high;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(help(nums, mid) <= threshold)
            {
                ans = mid;
                high = mid-1;
                cout<<ans<<" ";
            }
            else
                low = mid + 1;
        }
        
return ans;
    }
};