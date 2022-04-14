class Solution {
public:
    
    //Similar to Merge K-Sorted List
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        for(int i=0; i<n1; i++)
        {
            vector<int> arr = {nums1[i] + nums2[0], i, 0};
            pq.push(arr);
        }
        
        vector<vector<int>> ans;
        
        while(k>0 && !pq.empty())
        {
            auto popped = pq.top();
            pq.pop();
            
            int i = popped[1];
            int j = popped[2];
            
            ans.push_back({nums1[i], nums2[j]});
            k--;
            
            if(j == n2-1)
                continue;
            
            pq.push({nums1[i] + nums2[j+1], i, j+1});
        }
        
        return ans;
        
    }
};