class Solution {
public:
    //Not Acceptable
// int divide(int dividend, int divisor) 
// {
//         long long ans = 0;
//         double x = pow(divisor,-1);
//         ans = dividend*x;
    
//         if(ans>INT_MAX)
//             return INT_MAX;
    
//         if(ans<INT_MIN)
//             return INT_MIN;
            
//         return int(ans);
//     }
    
    int divide(int divd, int divs)
    {

        if(divd == INT_MIN and divs == -1)
            return INT_MAX;

        bool positiveSign = (divd < 0 == divs < 0);

        long dividend = abs(divd);
        long divisor = abs(divs);

        long ans = 0;

        while(dividend >= divisor)
        {

            long divisor2 = divisor;
            long divisorMultipliedBy = 1;

            while(dividend >= (divisor2 << 1))
            {

                divisor2 = divisor2 << 1;
                divisorMultipliedBy = divisorMultipliedBy << 1;
            }

            ans+= divisorMultipliedBy;
            dividend -= divisor2;
        }
                  

        if(positiveSign)
            return ans;
        
        return ans * -1;
    }
};