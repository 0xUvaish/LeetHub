class Solution {
public:
bool static comp(pair<int, int> &A, pair<int, int> &B)
{
    if(A.first!=B.first)
        return A.first<B.first;
    else
        return A.second<B.second;
}
    
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans(k);
        vector<pair<int, int>> help;
        
        int m=mat.size(), n=mat[0].size();
        for(int i=0;i<m;i++)
        {
            int count=0;
            int low =0, high = n-1, tans=n;
            while(low<=high)
            {
               int mid = low + (high-low)/2;
                if(mat[i][mid] ==0)
                {
                    high = mid-1;
                    tans = mid;
                }
                else
                    low = mid + 1;
            }
            help.push_back({tans-1, i});
        }
        
        sort(help.begin(), help.end());

for(int i=0;i<k;i++)
    ans[i]=help[i].second;
        
    return ans;
    }
};