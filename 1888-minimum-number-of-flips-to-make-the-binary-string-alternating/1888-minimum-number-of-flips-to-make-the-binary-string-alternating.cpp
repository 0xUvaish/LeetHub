class Solution {
public:
    //Method 1: Brute Force O(n^2) Solution
    //Move 0 to n-1 character one by one - Type I and for each move Check for min flips to make alternating ->  n*n Solution
    
    //Method 2: Sliding Window (Fixed Size): O(n)
    int minFlips(string s)
    {
        int n = s.size();
        
        string ss = s+s;
        int m = ss.size();
        string alt1="", alt0="";
        
        for(int i=0;i<m;i++)
        {
            if(i%2==0)
            {
                alt1 += '1';
                alt0 += '0';
            }
            else
            {
                alt1 += '0';
                alt0 += '1';
            }
        }
        
        
        int diff0=0, diff1=0, ans=INT_MAX;
        
        int i=0;
        for(int j=0;j<m;j++)
        {
            if(ss[j] != alt1[j])
                diff1++;
            if(ss[j] != alt0[j])
                diff0++;
            
            if(j-i+1 > n)      //Out of bounds for i
            {
                if(ss[i] != alt1[i])
                    diff1--;
                if(ss[i] != alt0[i])
                    diff0--; 
                
                i++;
            }
            
            if(j-i+1 == n)    //Window Size hit
            {
               ans = min({ans, diff1, diff0}); 
            }
        }
        
    return ans;
        
    }
};