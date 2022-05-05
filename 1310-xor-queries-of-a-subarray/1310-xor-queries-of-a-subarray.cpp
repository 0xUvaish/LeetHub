class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> preXOR(n);
        
        preXOR[0]=arr[0];
        for(int i=1;i<n;i++)
            preXOR[i] = preXOR[i-1]^arr[i];
        
        int m = queries.size();
        vector<int> ans(m);
        ans.clear();
        
        for(auto x: queries)
        {
            int l=x[0];
            int r=x[1];
            if(l>0)
                ans.push_back(preXOR[r]^preXOR[l-1]);
            else
                ans.push_back(preXOR[r]);
        }
        
    return ans;
    }
};