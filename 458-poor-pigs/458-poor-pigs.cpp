class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
         int T = minutesToTest/minutesToDie;         
        return ceil(log10(buckets)/log10(T+1));        
    }
};