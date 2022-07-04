class Solution {
public:
    int get2dSum(vector<vector<int>> &ps, int c1, int c2, int r) 
    {
        return ps[r + 1][c2 + 1] - ps[r + 1][c1];
    }
    
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int rSize = matrix.size();
        int cSize = matrix[0].size();
        vector<vector<int>> ps(rSize + 1, vector<int>(cSize + 1, 0));
        
        for (int r = 1; r <= rSize; r++) 
            for (int c = 1; c <= cSize; c++) 
                ps[r][c] = ps[r - 1][c] + ps[r][c - 1] - ps[r - 1][c - 1] + matrix[r - 1][c - 1];
        
        int res = 0;
        unordered_map<int, int> map;
        
        for (int c1 = 0; c1 < cSize; c1++)
        {
            for (int c2 = c1; c2 < cSize; c2++) 
            {
                //Hashing now
                map[0] = 1;
                for (int r = 0; r < rSize; r++) 
                {
                    int currSum = get2dSum(ps, c1, c2, r);
                    if(map.count(currSum - target)) 
                        res += map[currSum -target];
                    
                    map[currSum]++;
                }
                map.clear();
            }
        }
        return res;
    }
};