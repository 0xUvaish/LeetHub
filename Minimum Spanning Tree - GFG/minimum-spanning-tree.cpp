// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
   int* parent;
   int* rank;

public:
void DSU(int n)
{
       parent = new int[n];
       rank = new int[n];
       for (int i = 0; i < n; i++) 
       {
           parent[i] = -1;
           rank[i] = 1;
       }
   }
   
   int find(int i)
   {
       if (parent[i] == -1)
           return i;

       return parent[i] = find(parent[i]);
   }
   
    void unite(int x, int y, int s1, int s2)
    {
       if (rank[s1] < rank[s2])
       {
           parent[s1] = s2;
           rank[s2] += rank[s1];
       }
       else
       {
           parent[s2] = s1;
           rank[s1] += rank[s2];
       }
   }

   
   int spanningTree(int V, vector<vector<int>> adj[])
   {

       vector<vector<int>> edgelist;
       for(int i=0;i<V;i++)
       {
           for(auto j:adj[i])
           {
              edgelist.push_back({j[1],i,j[0]});
           }
       }
       
       sort(edgelist.begin(), edgelist.end());
       
       DSU(V);
       
       int ans=0;
       for (auto edge : edgelist) 
       {
           int w = edge[0];
           int x = edge[1];
           int y = edge[2];
           int s1 = find(x);
           int s2 = find(y);
           if (s1 != s2)
           {
               unite(x,y,s1,s2);
               ans += w;
           }
       }
       return ans;
   }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends