class Solution {
public:
    
    uint32_t reverseBits(uint32_t n) 
    {
        int ans = 0;
        for (int i = 0; i < 31; i++)
        {
            int temp = n%2;
            n = n>>1;
            ans += temp;
            ans = ans<<1;
        }
        
        ans += n;
        return ans;
    }
};