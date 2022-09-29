class Solution {
public:
//  https://leetcode.com/problems/find-k-closest-elements/discuss/1311197/Find-K-Closest-Elements-or-All-Possible-Approaches-Explained-w-Simple-Solutions!
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {        
        int n = size(arr), R = lower_bound(begin(arr), end(arr) - k, x) - begin(arr), L = R - 1;
        while(k--) 
            if(R >= n || L >= 0 && x - arr[L] <= arr[R] - x) L--;
            else R++;
        return vector<int>(begin(arr) + L + 1, begin(arr) + R);
    }
};