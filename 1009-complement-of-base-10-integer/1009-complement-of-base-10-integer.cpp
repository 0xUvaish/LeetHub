class Solution {
public:
    int bitwiseComplement(int n) 
    
    {
          if(n==0)         //Base Case   
              return 1;
	  
	  /*  If number is even than it's last bit must be 0 and if it's odd it must be 1.
	  We will make use of this fact only*/
	  
	     int p=1, sum=0;
		 
		 /* p will be used to calculate the value of bit at specific position. If number is even we will add value of p in our sum since it's current last digit would be 0 and that will be 1 in complemented number. Then we will divide the number by 2 and get rid of calculated bit and move on to next bit*/ 
	  
        while(n>0)
        {
            if(n%2==0)
                sum+=p;
           
            n=n>>1;  /*n has been shifted to right to make it half*/
            p=p<<1; /* p has been shifted left to keep calculating value of bit at specific position such as 1, 2, 4, 8......*/
        }
        
        return sum;
    }
};