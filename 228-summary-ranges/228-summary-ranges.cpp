class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int flag=0, n=nums.size();
        vector<string> ans;
        string a;
        if(n==0)
            return ans;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]+1)
                continue;
            else
            {
                if(i-flag==1)
                    a = to_string(nums[flag]);
                else
                    a = to_string(nums[flag]) + "->" + to_string(nums[i-1]);
                
                ans.push_back(a);
                flag = i;
            }
        }
    if(n-flag==1)
        a = to_string(nums[flag]);
    else
        a = to_string(nums[flag]) + "->" + to_string(nums[n-1]);
        
    ans.push_back(a);
        
        return ans;
    
    }
};