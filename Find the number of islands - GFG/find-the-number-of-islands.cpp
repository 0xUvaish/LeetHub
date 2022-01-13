// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
        void DFSRec(vector<vector<char>> &mat, int N, int M, int i, int j)
        {
        if(i >= 0 and i < N and j >= 0 and j < M and mat[i][j] == '1')
        {
            mat[i][j] = '2';
            DFSRec(mat, N, M, i, j+1);
            DFSRec(mat, N, M, i, j-1);
            DFSRec(mat, N, M, i-1, j);
            DFSRec(mat, N, M, i+1, j);
            DFSRec(mat, N, M, i+1, j+1);
            DFSRec(mat, N, M, i+1, j-1);
            DFSRec(mat, N, M, i-1, j-1);
            DFSRec(mat, N, M, i-1, j+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
       int count = 0;
        
        int N = grid.size();
        int M = grid[0].size();
    
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(grid[i][j] == '1')
                {
                    DFSRec(grid, N, M, i, j);
                    count++;
                }
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends