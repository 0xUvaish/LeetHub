// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
    vector<int>res;
       queue<int>q;
       vector<bool>visited(V,false);
       q.push(0);
       while(!q.empty())
       {
           int f=q.front();
           q.pop();
           res.push_back(f);
           
           for(auto i=0;i<adj[f].size();i++)
           {
               if(!visited[adj[f][i]])
               {
                   q.push(adj[f][i]);
                   visited[adj[f][i]]=true;
               }
           }
           
       }
       return res;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends