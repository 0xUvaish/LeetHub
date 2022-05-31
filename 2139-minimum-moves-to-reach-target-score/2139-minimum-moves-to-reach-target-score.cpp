class Solution {
public:
    int minMoves(int target, int maxDoubles) 
    {
        if(maxDoubles == 0)
            return target - 1;
        
        if(target == 1)
            return 0;
        
        int n = target;
        int count = 0;
        
        while(maxDoubles > 0 && n >= 1)
        {
            if(n % 2 == 0)
            {
                n = n / 2;
                maxDoubles--;
            }
            else
                n = n - 1; 
            count++;
            
            if(n == 1)
                return count;
        }
        
        if(n > 1) 
            count+= n - 1;
        
        return count;
    }
};