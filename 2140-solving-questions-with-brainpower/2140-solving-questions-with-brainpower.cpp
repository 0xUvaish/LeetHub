class Solution {
private:
    vector<long long> maxes;

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int N = questions.size();
        maxes.assign(N + 1, -1);
        
        for (int idx = N - 1; idx >= 0; idx--) {
            long long points = questions[idx][0];
            if (questions[idx][1] + idx + 1 < N) {
                points += maxes[idx + questions[idx][1] + 1];
            }
            maxes[idx] = max(maxes[idx + 1], points);
        }

        return *max_element(maxes.begin(), maxes.end());
    }
};