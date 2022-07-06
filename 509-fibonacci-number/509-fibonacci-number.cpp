class Solution {
public:
    int fib(int n) {
        
        if(n==0)
            return 0;
        if(n==1)
            return 1;
    int a=0,b=1,c;
        while(n-2>=0)
        {
            c=b+a;
            a=b;
            b=c;
            n--;
        }
    return c;
    }
};