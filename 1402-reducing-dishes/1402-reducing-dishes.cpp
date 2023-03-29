class Solution {
public:
    int maxSatisfaction(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), greater<int>());

        for(int i = 1; i < n; i++)
            arr[i] += arr[i - 1];

        int sum = 0, maxi = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            maxi = max(maxi, sum);
        }        
        
        return maxi;
    }
};