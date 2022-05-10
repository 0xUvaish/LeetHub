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
        
        stack<int> st;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                st.push(i);
            }
        }
        
        int studied = 0;
        while (!st.empty()) {
            int currCourse = st.top();
            st.pop();
            
            ++studied;
            for (int& nextCourse : digraph[currCourse]) {
                --indegree[nextCourse];
                if (indegree[nextCourse] == 0) {
                    st.push(nextCourse);
                }
            }
            
        } 
        
        if (studied != numCourses) {
            return false;
        }
        return true;
    }
};