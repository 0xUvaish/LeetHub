class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int diff=INT_MAX;
        
        for(int i=0; i<arr.size()-1; ++i)
        {
            int x = arr[i], y = arr[i+1];
            if(abs(x-y) < diff)
            { 
                ans.clear();
                ans.push_back({x,y});
                diff=abs(x-y);
            }
            else if(abs(x-y) == diff) 
                ans.push_back({x,y});
        }
        
    return ans;  
    }
};