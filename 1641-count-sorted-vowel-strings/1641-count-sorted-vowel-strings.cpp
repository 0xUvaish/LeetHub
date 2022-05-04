class Solution {
public:
    
    //Method 3 - PnC - Combination with repetition - !(n-1+r)/!(r)!(n-1) 
    // n = 5, r = n(n provided in question)
    // === ((n+1)*(n+2)*(n+3)*(n+4))/4
    int countVowelStrings(int n) {
        return ((n+1)*(n+2)*(n+3)*(n+4))/24;
    }
};