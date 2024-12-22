class Solution {

    void buildTree (vector<int>& sTree, int idx, int start, int end, const vector<int>& a) {
        if (start == end) {
            sTree[idx] = a[start];
            return;
        }
        int mid = (start+end)/2;
        buildTree (sTree, 2*idx+1, start, mid, a);
        buildTree (sTree, 2*idx+2, mid+1, end, a);
        sTree[idx] = max(sTree[2*idx+1], sTree[2*idx+2]);
    }

    int queryTree (const vector<int>& sTree, int idx, int start, int end, int qs, int qe) {

        if (qs > end || qe < start) return INT_MIN;
        if (start>=qs && end<=qe) return sTree[idx];
        int mid = (start+end)/2;
        int shortAns1 = queryTree (sTree, 2*idx+1, start, mid, qs, qe);
        int shortAns2 = queryTree (sTree, 2*idx+2, mid+1, end, qs, qe);
        return max(shortAns1, shortAns2);
    }

    int findAns (const vector<int>& sTree, int n, int left, int mini) {
        int start = left, end = n-1, ans = n;
        while (start <= end) {
            int mid = (start+end)/2;
            int shortQuery = queryTree (sTree, 0, 0, n-1, start, mid);
            if (shortQuery >= mini) {
                ans = mid, end = mid-1;
            } 
            else {
                start = mid+1;
            }
        }
        return ans;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> sTree(4*n,0);
        buildTree (sTree, 0, 0, n-1, heights);
        int q = queries.size();
        vector<int> ans(q,-1);
        for (int i=0; i<q; i++) {
            int leftMost = max(queries[i][0], queries[i][1]);
            int minimumRequired = max(heights[queries[i][0]], heights[queries[i][1]]);
            if (queries[i][0] == queries[i][1]) ans[i] = queries[i][0];
            else if (queries[i][0] > queries[i][1] && heights[queries[i][0]]>heights[queries[i][1]]) ans[i] = queries[i][0];
            else if (queries[i][1] > queries[i][0] && heights[queries[i][1]]>heights[queries[i][0]]) ans[i] = queries[i][1];
            else {
                int queryAns = findAns (sTree, n, leftMost, minimumRequired+1);
                if (queryAns < n) ans[i] = queryAns;
            }
        }
        return ans;
    }
};