class Solution {
public:
    int mySqrt(int x) {
        long long low = 0, high = x, ans=-1;
        
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            if(mid*mid == x)
                return ans=mid;
            else if(mid*mid < x)
            {
                ans = mid;
                low = mid + 1;
            }
            
            else
                high = mid - 1;
        }
    return ans;
    }
};