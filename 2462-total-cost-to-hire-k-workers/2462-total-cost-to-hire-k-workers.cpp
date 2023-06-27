class Solution {
public:
    typedef pair<int, int> pii;

    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        int l = 0, r = n - 1;
        priority_queue<pii, vector<pii>, greater<pii>> pq; 
        long long res = 0;

        if(n <= 2 * candidates){
            sort(costs.begin(), costs.end());
            int p = 0;
            while(k --) res += costs[p ++];
        }

        else{
            while(candidates --){
                pq.push({costs[l ++], 0});
                pq.push({costs[r --], 1});
            }

            while(k --){
                auto cur = pq.top(); pq.pop();
                res += cur.first;

                if(l <= r){
                    if(cur.second == 0) pq.push({costs[l ++], 0});
                    else pq.push({costs[r --], 1});
                }
            }
        }


        return res;
    }
};