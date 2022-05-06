class Solution {
public:
    int bitwiseComplement(int n) 
    
    {
          if(n==0)   
              return 1;
	  
	  /*  If number is even than it's last bit must be 0 and if it's odd it must be 1.
	  We will make use of this fact only*/
	  
	    int p=1, sum=0;
        while(n>0)
        {
            if(n%2==0)
                sum+=p;
           
            n=n>>1;
            p=p<<1;
        }
        
        return sum;
    }
};