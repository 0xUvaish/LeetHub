class Solution {
public:
    
bool dfs(int node, vector<vector<int>> &graph, vector<int> &col)
{
        if(col[node] == -1)
            col[node] = 1;
    
        for(auto it: graph[node])
        {
            if(col[it]==-1)
            {
                col[it]=1-col[node];
                if(!dfs(it, graph, col))
                    return false;
            }
            else if(col[it]==col[node])
                return false;
        }
        return true;
    }
    
bool isBipartite(vector<vector<int>>& graph) 
{
        int n = graph.size();
        vector<int> col(n, -1);
        
        for(int i=0;  i<n; i++)
            if(col[i] == -1)
                if(!dfs(i, graph, col))
                    return false;
    
        return true;
        
    }

};