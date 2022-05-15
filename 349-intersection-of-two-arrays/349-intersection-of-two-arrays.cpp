class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        vector<int> res;
        
        for (auto num : nums1)
            freq[num]++;
        
        for (auto num : nums2)
            if (freq[num])
            {
                res.push_back(num);
                freq[num]=0;
            }
        
        return res; 
    }
};