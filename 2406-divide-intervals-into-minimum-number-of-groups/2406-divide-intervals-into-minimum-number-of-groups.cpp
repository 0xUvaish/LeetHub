class Solution {
public:
    
    // https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/discuss/2560018/C%2B%2B-or-Line-Sweep-or-Related-Problems
    int minGroups(vector<vector<int>>& intervals) {

        int line[1000005] = {};
        int maxEle = -1;

        for(auto &e : intervals) {
            int start = e[0], end = e[1];
            line[start] += 1;
            line[end + 1] -= 1;
        }

        for(int i = 1; i < 1000001; i++) {
            line[i] += line[i - 1];
            maxEle = max(maxEle, line[i]);
        }

        return maxEle;
    }
};