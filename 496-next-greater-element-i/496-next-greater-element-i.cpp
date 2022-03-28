class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums2.size();
        stack<int> st;
        unordered_map<int, int> mp;
        vector<int> ans;
        
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && nums2[i]>=st.top())
            st.pop();
        
        if(st.empty())
            mp[nums2[i]]=-1;
        else
            mp[nums2[i]]=st.top();
        
        st.push(nums2[i]);
    }
        
    for(auto x: nums1)
        ans.push_back(mp[x]);
        
    return ans;

    }
};