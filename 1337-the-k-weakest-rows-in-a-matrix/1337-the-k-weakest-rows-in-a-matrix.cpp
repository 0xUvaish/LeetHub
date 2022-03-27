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
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                    count++;
            }
            help.push_back({count, i});
        }
        
        sort(help.begin(), help.end());

for(int i=0;i<k;i++)
    ans[i]=help[i].second;
        
    return ans;
    }
};