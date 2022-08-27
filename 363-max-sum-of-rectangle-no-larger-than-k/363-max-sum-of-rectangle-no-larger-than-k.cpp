// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/2485706/C%2B%2B-Clean-Code-or-Similar-to-2D-Kadane-approach
class Solution {
public:
    
    int sumNoLargerThanK_1D_array(vector<int> &v,int k){
        set<int> prefSet;
        prefSet.insert(0);
        int curSum = 0, curMax = INT_MIN;
        for (int sum : v) {
            curSum += sum;
            auto it = prefSet.lower_bound(curSum - k);
            if (it != prefSet.end()) curMax = max(curMax, curSum - *it);
            prefSet.insert(curSum);
        }
        return curMax;
    }
    
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = -1e8;
        for (int l = 0; l < n; ++l) {
            vector<int> v(m, 0);
            for (int r = l; r < n; ++r) {
                for (int i = 0; i < m; ++i) {
                    v[i] += matrix[i][r];
                }
                res=max(res,sumNoLargerThanK_1D_array(v,k));
            }
        }
        return res;
    }
};