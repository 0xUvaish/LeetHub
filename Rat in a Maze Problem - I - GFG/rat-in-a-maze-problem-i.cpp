// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    vector<string>ans;
    vector<vector<int>>util={{0,1},{1,0},{0,-1},{-1,0}};
    
    char direction(int i,int j){
    if(i==1 && j==0)return 'D';
    if(i==0 && j==1)return 'R';
    if(i==-1 && j==0)return 'U';
    if(i==0 && j==-1)return 'L';
}
void solve(vector<vector<int>> &grid,int i,int j,int n,string out)
{
    if(i<0 || j<0 || i>=n || j>=n || grid[i][j]!=1)
        return;
        
    if(i==n-1 && j==n-1)
    {
        ans.push_back(out);
        return;
    }
    
    grid[i][j]=2;
    for(int k=0;k<4;k++){
        int x=i+util[k][0];
        int y=j+util[k][1];
        out.push_back(direction(util[k][0],util[k][1]));
        solve(grid,x,y,n,out);
        out.pop_back();
    }
    grid[i][j]=1;
}

    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        
    solve(m,0,0,n,"");
    sort(ans.begin(),ans.end());
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