class Solution {
public:
    
// Right Shift Method
// int hammingWeight(uint32_t n) 
// {
//         int count = 0;
//         while (n!=0) 
//         {
//             if(n&1)
//                 count++;
            
//             n = n>>1;
//         }
    
//         return count;
//     }
    

// n&(n-1) Method - O(No. of set bits only) - Optimised
    
int hammingWeight(uint32_t n) 
{
        int count = 0;
        while (n!=0) 
        {
            count++;            
            n = (n & (n-1));
        }
    
    return count;
    
    }
};