class Solution {
public:
    int trailingZeroes(int n)
    {
      int ans = 0;

     for(int i=5; i<=n; i=i*5) //log n base 5 < log n base 2  
        ans += n/i;            // or single line as n/5 + n/25 + n/125 + n/625 + n/3125
    
    return ans;
 }

};