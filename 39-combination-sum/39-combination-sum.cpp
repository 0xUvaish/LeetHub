class Solution {

public:
     vector<vector<int>>result;
     void solve(vector<int>& candidates, int target, int sum, vector<int>& temp, int idx){
        
         if(sum>target)
            return;
    
        if(sum==target)
        {
            result.push_back(temp);
            return;
        }
        for(int i=idx;i<candidates.size();i++)
        {
                temp.push_back(candidates[i]);
                solve(candidates, target, sum+candidates[i], temp, i); //index i (not i+1) because we can take more than once
                temp.pop_back();
        }
         return;
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> temp;
        int sum=0;
        solve(candidates, target, sum, temp, 0);
        return result;
    }
       
};