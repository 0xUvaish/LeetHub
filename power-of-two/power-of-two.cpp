class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (log2(n) - floor(log2(n)) == 0) ? true: false;
    }
};