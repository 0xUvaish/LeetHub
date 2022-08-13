class Solution {
public:
    // https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/discuss/624185/C%2B%2B-sliding-window-easy-solution
    
    //M1: Two Pointer Sliding Window nlogn approach
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        vector<pair<int, int>> ordered; // (number, group id)
        for (size_t k = 0; k < nums.size(); ++k)
            for (auto n: nums[k]) ordered.push_back({n, k});
        
        sort(ordered.begin(), ordered.end());

        int i = 0, k = 0;
        vector<int> ans;
        unordered_map<int, int> count;
        for(size_t j = 0; j < ordered.size(); ++j) 
        {
            if(!count[ordered[j].second]++) //New list element found
                ++k;
            
            if(k == nums.size()) //All lists covered
            { 
                while (count[ordered[i].second] > 1)
                    --count[ordered[i++].second]; // minimize range
                
                if (ans.empty() || ans[1] - ans[0] > ordered[j].first - ordered[i].first) 
                    ans = vector<int>{ordered[i].first, ordered[j].first};
            }
        }

        return ans;
    }
};