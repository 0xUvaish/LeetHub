class Solution {
public:
    
/* sqrt(n) Solution
int arrangeCoins(int n) {
       int i=1,rows=0; 
        while(n>=i)
        {
            rows++;
            n-=i;
            i++;
        }
    return rows;
    }
*/
  
    
/* O(logn) Solution
int arrangeCoins(int n)
{
    long low=1, high=n, ans=0;
    while(low<=high)
    {
        long mid =(low+high)/2;
        long count= (mid*(mid+1))/2;
        
        if(count==n)
            return mid;
        
        if(count<n)
        {
            ans = mid;
            low= mid+1;
        }
        else
            high = mid-1;
           
    }
    return ans;
 }
 
 */
    
    int arrangeCoins(int n)
    
    {
      // Tk = k(k+1)/2 where k is the number of rows (here Tk is n). Lookup Triangular Numbers if interested
      // k^2 + k <= 2Tk
      // (k + .5)^2 <= 2Tk + .25      (complete the square)
      // k <= sqrt(2Tk + .25) - .5    (solve for k)
      return (int)(sqrt(2*(double)n + .25) - .5);
    }
 
    
};