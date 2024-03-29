class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        
        while(n) 
        {
            if(n%2)
            {
                if(n > 0) 
                    res = res * x;
                else
                    res = res / x;
            }
            
            x = x * x;
            n = n / 2;
        }
        
        return res;
    }
};