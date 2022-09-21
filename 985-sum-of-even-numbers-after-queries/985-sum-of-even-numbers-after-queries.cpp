class Solution {
public:
vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
       
        vector<int> ans;
        int sum=0;
    
        for(auto x:nums)
            if(x%2==0)
                sum+=x;
    
        for(auto query:queries)
        {
            int old = nums[query[1]];   
            int val = query[0];  
            
            nums[query[1]]=old+val; 
            
            if(old%2==0 && val%2==0)   
                sum+=val;
            else if(old%2==0 && val%2!=0)
                sum-=old;
            else if(old%2!=0 && val%2!=0)    
                sum+=old+val;
            
            ans.push_back(sum);       
        }
        return ans;
    }
};