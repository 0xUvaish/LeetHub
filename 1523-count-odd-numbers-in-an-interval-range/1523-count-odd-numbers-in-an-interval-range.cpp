class Solution {
public:
    int countOdds(int low, int high) {
        return high%2 ? (high-low+2)/2 : (high-low+1)/2; 
    }
};