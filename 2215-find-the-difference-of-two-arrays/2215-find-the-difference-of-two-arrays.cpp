class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(),nums1.end()),s2(nums2.begin(),nums2.end());
        vector<vector<int>> ans(2);
        int val;
        for(auto it=s1.begin();it!=s1.end();++it)
        {
            val=*it;
            if(s2.find(val)==s2.end())
            ans[0].push_back(val);

        }
        for(auto it=s2.begin();it!=s2.end();++it)
        {
            val=*it;
            if(s1.find(val)==s1.end())
            ans[1].push_back(val);

        }
        return ans;
    }
};