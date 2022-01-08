class Solution {
public:
void dfs(int i, int target, vector<int> &arr, vector<vector<int>> &res, vector<int> &ds)
    {
        if (target == 0) 
        {
            res.push_back(ds); 
            return;
        }

        for (int j = i; j < arr.size(); j++) 
        {
            if (j > i && arr[j] == arr[j-1]) 
                continue; 
            if (arr[j] > target)
                break;

            ds.push_back(arr[j]); 
            dfs(j+1, target - arr[j], arr, res,ds); 
            ds.pop_back(); 
        }
    }

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> res;
        vector<int> ds; 
        sort(candidates.begin(), candidates.end()); 
        dfs(0, target, candidates, res,ds); 
        return res;

    }
};