class Solution {
public:
bool checkPowersOfThree(int n) {
        while(n)
        {
            if(n % 3 > 1)  //only 0,1 allowed.
                return false;
            n /= 3;
        }
        return true;
    }
};