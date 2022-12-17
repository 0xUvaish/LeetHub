class Solution {
public:
    //No. of set bits method
    int hammingDistance(int x, int y) {
        
        int n = x ^ y, count = 0;
        while(n > 0) 
        {
            count++;
            n = n & (n - 1);
        }

        return count;
    }
};