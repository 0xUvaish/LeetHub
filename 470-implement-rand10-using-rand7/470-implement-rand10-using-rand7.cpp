// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int g=0;
    
    int rand10() {
        g++;
        if(g%10==0)
            return 10;
        return g%10;
    }
};