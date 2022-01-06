class Solution {
public:
    vector<int> temp; 
    vector<vector<int>> res;
    int target;
    
    void dfs(vector<vector<int>>& graph, int node = 0)
    {
        temp.push_back(node);
        
        if(node == target)
            res.push_back(temp);
        else
            for(int it : graph[node])
                dfs(graph, it);
        
        temp.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        target = graph.size() - 1 ;
        dfs(graph);
        return res;
    }
};