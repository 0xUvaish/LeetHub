class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = size(strs), m = size(strs.front()),ct=0;
        for(int j=0; j<m; ++j){
            string t;
            for(int i=0; i<n; ++i)
                t += strs[i][j];
            if(!is_sorted(begin(t),end(t))) ct++;
        }
        return ct;
    }
};