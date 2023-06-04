   //Solution 1 --> DFS Start (BFS Also similar)

class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int start, vector<bool>& visited)
      {

        visited[start] = true;          
        for (int nb : graph[start])
         {
            if(!visited[nb])
                dfs(graph, nb, visited);
         }
            
        }
    
    
int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size();
        vector<vector<int>> graph(n);
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (!isConnected[i][j])
                    continue;

                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            if(visited[i])
                continue;
            count++;
            dfs(graph, i, visited);        
        }
        
    return count;
    }
    

    
};      // Solution 1 --> DFS Ends (BFS Also similar)




//Solution 2 - DSU Starts
// class UnionFind {
// public:
//     UnionFind(vector<vector<int>>& isConnected)
//     {
//         n = isConnected.size();
//         parent = vector<int>(n);
//         count = n;
        
//         for (int i = 0; i < n; i++)
//         {
//             parent[i] = i;
//         }
        
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (!isConnected[i][j])
//                     continue;
                
//                 Union(i, j);                    
//             }
//         }
//     }
    
//     void Union(int i, int j)
//     {
//         int p1 = Find(i);
//         int p2 = Find(j);
//         if (p1 != p2)
//         {
//             parent[p1] = j;
//             count--;
//         }           
//     }
    
//     int Find(int i)
//     {
//         while (parent[i] != i)
//         {
//             parent[i] = parent[parent[i]];
//             i = parent[i];
//         }
        
//         return i;
//     }
    
//     int Count()
//     {
//         return count;
//     }
    
    
// private:
//     int n;
//     int count;
//     vector<int> parent;
// };

// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         UnionFind uf(isConnected);
//         return uf.Count();
//     }
// };

//Solution 2 - DSU Ends