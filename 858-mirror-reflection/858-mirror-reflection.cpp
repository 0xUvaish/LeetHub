class Solution {
public:
    int mirrorReflection(int p, int q) {
        // reducing p and q if/while both even
        while (p % 2 == 0 && q % 2 == 0) p >>= 1, q >>= 1;
        
        return p % 2 ? q % 2 : 2;
    }
};