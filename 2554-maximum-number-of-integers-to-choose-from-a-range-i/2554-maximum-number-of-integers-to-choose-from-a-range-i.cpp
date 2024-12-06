class Solution {
public:
int maxCount(vector<int>& ban, int n, int maxSum) {
    int ps[10001] = {}, l = 0, r = n, cnt = 0;
    for (int b : ban)
        ps[b] = b;
    partial_sum(begin(ps), end(ps), begin(ps));
    while (l < r) {
        if (int m = (l + r + 1) / 2; m * (m + 1) / 2 - ps[m] > maxSum)
            r = m - 1;            
        else
            l = m;
    }
    for (int i = 0; i < l; ++i)
        cnt += ps[i] != ps[i + 1];
    return l - cnt;
}
};