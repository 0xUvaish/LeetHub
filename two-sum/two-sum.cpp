class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>m;
        
        for(int i=0;i<n;i++)
            m.insert({nums[i],i});
        
        for(int i=0;i<n;i++)
        {
           if(m.find(target-nums[i]) != m.end() and i!=m[target-nums[i]])
           {
               ans.push_back(i);
               ans.push_back(m[target-nums[i]]);
               return ans;
           }
        }
       return ans;   
    }
};