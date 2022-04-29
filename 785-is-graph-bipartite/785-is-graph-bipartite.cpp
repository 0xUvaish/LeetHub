class Solution {
public:
    
bool dfs(int node, vector<vector<int>> &graph, vector<int> &col, int cur){
        if(col[node] != -1)
        {
            if(col[node] == cur) 
                return true;
            else
                return false;
        }
        
        col[node] = cur;
        for(auto it: graph[node])
        {
            bool f = dfs(it, graph, col, 1-cur);
            if(!f) 
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
                if(!dfs(i, graph, col, 0))
                    return false;
    
        return true;
        
    }

};