class Solution {
public:
int numOfWays(int n) 
{
    int MOD=1e9+7;
    long long int x=6,y=6;
    n--;
    
    while(n--)
    {
        long long int threeColor=(2*x+2*y);
        long long int twoColor=(2*x+3*y);
        
        x=threeColor%MOD;
        y=twoColor%MOD;
    }
    
    return (x+y)%MOD;
    }
};