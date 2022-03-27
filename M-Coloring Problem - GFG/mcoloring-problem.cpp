// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101], int V, int color[], int node, int col)
{
    for(int k=0;k<V;k++)
    {
        if(k!=node && graph[k][node]==1 && color[k]==col)
        return false;
    }
    return true;
}

bool mColor(bool graph[101][101], int m, int V, int color[], int node)
{
    if(node==V)
        return true;
        
    for(int i=1;i<=m;i++)
    {
        if(isSafe(graph, V, color, node, i))
        {
            color[node]=i;
            if(mColor(graph, m, V, color, node+1))
                return true;
            color[node]=0;
        }
    }
    return false;
}


bool graphColoring(bool graph[101][101], int m, int V)
{
    int color[V];
    for(int i=0;i<V;i++)
        color[i]=0;
        
   if(mColor(graph, m, V, color, 0))
    return true;
    
    return false;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends