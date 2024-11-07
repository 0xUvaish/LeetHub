#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int largestCombination(std::vector<int>& nums) {
        int bits[32] = {0};
        for (int num : nums) {
            int j = 0;
            while (num > 0) {
                bits[j++] += num & 1;
                num >>= 1;
            }
        }
        return *std::max_element(bits, bits + 32);
    }
};