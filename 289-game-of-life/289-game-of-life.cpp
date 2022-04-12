class Solution 
{

    public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int n = board.size();
        int m = board[0].size();
        int nx, ny;
        
        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
        
        int live = 0;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++)
            {
                live = 0;
                for (int k = 0; k < 8; k++)
                {
                    nx = i + dx[k];
                    ny = j + dy[k];
                    if (nx < 0 or ny < 0 or nx >= n or ny >= m) 
                        continue;
                    
                    if (board[nx][ny] > 0) 
                        live++;    
                }
                
                if (board[i][j] == 1 && (live < 2 || live>3)) 
                    board[i][j] = 2;
                
                else if (board[i][j] == 0 && live == 3) 
                    board[i][j] = -1;
            }
        }
        
        //In Extra space we could have taken additional vector for pair of {changed value, {i,j}}
        
        //In O(1) Space, we directly manipulated original grid
        
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (board[i][j] == -1)
                    board[i][j] = 1;
                else if (board[i][j] == 2) 
                    board[i][j] = 0;
            }
        }
    }
};