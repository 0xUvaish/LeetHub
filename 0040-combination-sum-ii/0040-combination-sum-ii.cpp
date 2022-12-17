class Solution {
public:
void dfs(int idx, int target, vector<int> &arr, vector<vector<int>> &res, vector<int> &ds)
    {
        if(target==0) 
        {
            res.push_back(ds); 
            return;
        }

        for(int j=idx; j<arr.size(); j++) 
        {
            if(j!=idx && arr[j] == arr[j-1])        //To eliminate duplicate solutions Step II
                continue; 
            
            if(arr[j] > target)                   //Because all elements are going to be larger
                break;

            ds.push_back(arr[j]); 
            dfs(j+1, target-arr[j], arr, res, ds); 
            ds.pop_back(); 
        }
    }

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp; 
    
        sort(candidates.begin(), candidates.end()); //To eliminate duplicate solutions Step I
    
        dfs(0, target, candidates, ans, temp); 
        return ans;

    }
};