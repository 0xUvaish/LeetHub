class Solution {
public:
    int brokenCalc(int startValue, int target) {
        long long ans = 0;
        long long tar = target;
        while(startValue != tar)
        {
            if(tar%2 == 0 and startValue < tar)
                tar /= 2;
            
            else if(tar > startValue)
                tar +=1;
            
            else
            {
                ans += (startValue-tar)-1;
                tar = startValue;
            }
            
            
            ans++;
        }
        return ans;
    }
};