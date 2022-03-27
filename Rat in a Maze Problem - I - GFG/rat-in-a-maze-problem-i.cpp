// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    int di[4] = {1, 0, 0, -1};
    int dj[4] = {0, -1, 1, 0};
    void solve(vector<vector<int>> &m, int n, vector<vector<bool>> &visited, int row, int col, string asf)
    {
        if(row==n-1 && col==n-1)
            {
                ans.push_back(asf);
                return;
            }
            
        string dir="DLRU";
        for(int ind=0;ind<4;ind++)
        {
            int nexti = row+di[ind];
            int nextj = col+dj[ind];
            
            if(nexti>=0 && nexti<n && nextj>=0 && nextj<n && !visited[nexti][nextj] && m[nexti][nextj])
            {
                visited[nexti][nextj]=true;
                solve(m,n,visited,nexti,nextj,asf+dir[ind]);
                visited[nexti][nextj]=false;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        if(!m[0][0])
            return ans;
        string temp="";
        visited[0][0]=true;
        solve(m,n,visited,0,0,temp);
    return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends