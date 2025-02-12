class Solution {
public:
    //Sol1: Loop Method log4n
//     bool isPowerOfFour(int n) {
//          if(n<1)
//             return false;
//          if(n==1)
//             return true;
//         if(n%4!=0)
//             return false;
        
//     return isPowerOfFour(n/4);
//     }
    
//Sol2: Bit Manipulation
    bool isPowerOfFour(int n) {
        //return n>0 && (n&(n-1))==0 && (n&0x55555555);
		// n>0, n should be positive
		// n&(n-1) ensure it is power of 2
		// 5 is "0101" so n&0x55555... ensure that set bit is at the even position.
		// so if n is power of 2 and set bit is at even position -> n is power of 4
        
        
        return n>0 && (n&(n-1))==0 && !(n&0xAAAAAAAA); //negate mask approach
    }

};