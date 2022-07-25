class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        multiset<int> s(nums1.begin(), nums1.end());
        
        for(int i=0; i<n; i++)
        {
            int val = nums2[i];
            auto it = s.upper_bound(val);
            
            if(it != s.end())
            {
                nums1[i] = *it;
                s.erase(it);
            }
            else
                nums1[i] = -1;
        }
        
        for(int i=0; i<n; i++)
        {
            if(nums1[i] == -1)
            {
                nums1[i] = *s.begin();
                s.erase(s.begin());
            }
        }
        
        return nums1;
    }
};