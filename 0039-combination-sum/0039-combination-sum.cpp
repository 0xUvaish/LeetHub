class Solution {

public:
     vector<vector<int>>result;
     void solve(vector<int>& candidates, int target, int sum, vector<int>& temp, int idx){
    
        if(sum==target)
        {
            result.push_back(temp);
            return;
        }
        else if(sum>target)
            return;
         
        for(int i=idx;i<candidates.size();i++)
        {
            temp.push_back(candidates[i]);
            solve(candidates, target, sum+candidates[i], temp, i); //index i (not i+1) because we can take more than once
            temp.pop_back();
        }
     }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> temp;
        solve(candidates, target, 0, temp, 0);
        return result;
    }
       
};