class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult = start ^ goal;
        int count = 0;
        while (xorResult) {
            count++;
            xorResult &= (xorResult-1);
        }
        return count;
    }
};