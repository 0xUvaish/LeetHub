class Solution {
private:
    bool border(int i, int j, int m, int n) 
    {
        return (i == 0 or i == m-1 or j == 0 or j == n-1);
    }
    
    bool safe(int i, int j, int m, int n) 
    {
        return (i >= 0 and i < m and j >= 0 and j < n);
    }
    
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board) 
    {
        if(!safe(i, j, m, n) or board[i][j] != 'O')
            return;
        
        if(board[i][j] == 'O') board[i][j]='#';
        
        dfs(i + 1, j, m, n, board);
        dfs(i, j + 1, m, n, board);
        dfs(i - 1, j, m, n, board);
        dfs(i, j - 1, m, n, board);
    }
    
    void solve(vector<vector<char>>& board) 
    {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) 
                if(border(i, j, m, n) and board[i][j] == 'O') 
                    dfs(i, j, m, n, board);
        
        for(int i = 0; i < m; i++) 
        {
            for(int j = 0; j < n; j++) 
            {
                if(board[i][j] == 'O') 
                    board[i][j] = 'X';
                
                else if(board[i][j] == '#') 
                    board[i][j] = 'O';
            }
        }
    }

};