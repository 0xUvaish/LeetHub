class Solution {
public:
 
// Method 1 is (n & (n-1)) Count Set Bits Method using Loop
   bool isPowerOfTwo(int n)
   {
       int count=0;
       while(n>0)
       {
           count++;
           n = (n & (n-1));
       }
       
      return (count==1);
          
   }
    
//Method 2 without using Loop
    
    // bool isPowerOfTwo(int n) 
    // {
    //     return (log2(n) - floor(log2(n)) == 0) ? true: false;
    // }
};