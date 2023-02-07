class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> freq;
        int cnt = 0, mx = 0, p = -1;

        for (int i = 0; i < n; ++i) {
            if (!i)     p = i;

            ++freq[fruits[i]], ++cnt;

            while (freq.size() > 2) {
                int &fruit = fruits[p];
                
                --freq[fruit];
                if (freq[fruit] <= 0)   freq.erase(fruit);
                ++p, --cnt;
            }


            mx = max(mx, cnt);
        }

        return mx;
    }

};