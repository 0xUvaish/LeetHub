class Solution {
public:
    int reverse(int x) {
        long int rev=0;
        while(x!=0)
        { 
          int rem=x%10;
            rev=rev*10+rem;
            x=x/10;
            
        }
        
        if(rev <-2147483648 || rev >2147483648)
            return 0;
        else
            return rev;
        
        
    }
};