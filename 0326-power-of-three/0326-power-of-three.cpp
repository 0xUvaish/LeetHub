class Solution {
public:
    //M1: Loop Method log3n
//     bool isPowerOfThree(int n) {
//       if(n==0)
//         return false;
    
//     while(n)
//     {
//         if(n==1)
//             return true;
//         if(n<1)
//             return false;
//         if(n%3!=0)
//             return false;
//         n=n/3;
//     }
    
//     return true;     
//     }
    
    
    //M2: Without loops/recursion - logn still
    bool isPowerOfThree(int n) {
        if(n==0) 
            return false;
        
        float x=log(n)/log(3);
        return pow(3,x)==n;
    }
};