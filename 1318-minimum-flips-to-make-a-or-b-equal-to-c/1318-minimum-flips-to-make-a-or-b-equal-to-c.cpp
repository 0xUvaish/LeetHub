class Solution {
public:
    int countBits(int n)
    {
        int count=0;
        while(n>0)
        {
            count++;
            n = n>>1;
        }
    return count;     
    }
    
    int minFlips(int a, int b, int c) {
       
        int flips=0;
        int n = max({countBits(a), countBits(b), countBits(c)});
        
        for(int i=0;i<=31;i++)
        {
            
            if(c&(1<<i))
            {
              if((!(a&(1<<i))) && (!(b&(1<<i))))
                flips++;
            }
            else
            {
               if(a&(1<<i))
                   flips++;
               if(b&(1<<i))
                   flips++;               
            }
        }
        
    return flips;
    }
};