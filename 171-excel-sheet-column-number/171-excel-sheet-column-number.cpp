class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans = 0;
        for(char c : columnTitle)
        {
            int d = c - 'A' + 1;
            ans = ans * 26 + d;
        }
        return ans;
    }
};