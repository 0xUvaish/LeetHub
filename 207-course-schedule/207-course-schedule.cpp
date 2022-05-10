class Solution {
private:
    unordered_map<int, vector<int>> digraph;
    vector<int> indegree;
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        indegree.resize(numCourses, 0);
        for (vector<int>& edge : prerequisites) {
            ++indegree[edge[0]];
            digraph[edge[1]].push_back(edge[0]);
        }
        
        queue<int> qu;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                qu.push(i);
            }
        }
        
        int studied = 0;
        while (!qu.empty()) {
            int currCourse = qu.front();
            qu.pop();
            
            ++studied;
            for (int& nextCourse : digraph[currCourse]) {
                --indegree[nextCourse];
                if (indegree[nextCourse] == 0) {
                    qu.push(nextCourse);
                }
            }
            
        } 
        
        if (studied != numCourses) {
            return false;
        }
        return true;
    }
};