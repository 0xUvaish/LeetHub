class Solution {
public:
    int fib(int n) {
        
        if(n==0 || n==1)
            return n;
        
     int a=0,b=1,c;
        while(n>=2)
        {
            c=b+a;
            a=b;
            b=c;
            n--;
        }
    return c;
    }
};