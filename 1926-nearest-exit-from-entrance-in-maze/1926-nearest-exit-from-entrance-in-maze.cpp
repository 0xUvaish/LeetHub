class Solution {
public:
    vector<int> dir={-1,0,1,0,-1};
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<pair<int, int>,int>> pq;
        
        int x = entrance[0], y = entrance[1];
        int n = maze.size(), m = maze[0].size();
        maze[x][y] = '+';
        int ans = INT_MAX;
        
        pq.push({{x, y}, 0});
        
        while(!pq.empty())
        {
            int size = pq.size();
            while(size--)
            {
                auto top  = pq.front();
                pq.pop();
                for(int i = 0; i < 4; i++)
                {
                    int r = top.first.first + dir[i];
                    int c = top.first.second + dir[i + 1];
                    if(r >= 0 && c >= 0 && r < n && c < m && maze[r][c] != '+')
                    {
                        pq.push({{r, c}, top.second + 1});
                        maze[r][c] = '+';
                    }
                    
                    else if(r < 0 || c < 0 || r >= n || c >= m)
                        if(top.first.first != x || top.first.second != y) //in case entrance is itself a boundary cell
                            ans = min(ans , top.second);
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};