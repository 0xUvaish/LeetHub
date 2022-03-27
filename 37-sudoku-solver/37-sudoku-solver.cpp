class Solution {
public:
        bool flag = false;
    
        bool issafe(vector<vector<char>>& board, int row, int col, char digit)
        {
        
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==digit)
                return false;
            if(board[row][i]==digit)
                return false;
        }
            
        int startr = (row/3) * 3;
        int startc = (col/3) * 3;
            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                  if(board[i+startr][j+startc]==digit)
                      return false;
                }
            }
        
        return true;
            
    }
    bool solveSudoku(vector<vector<char>>& board, int row, int col)
    {
        if(row==9)
        {
            return true;
            
        }
        
        int newr=row;
        int newc=col+1;
        
        if(col==8)
        {
            newr = row+1;
            newc = 0;
        }
        
        if(board[row][col]=='.')
        {
            for(char digit='1';digit<='9';digit++)
            {
                if(issafe(board, row, col, digit))
                {
                    board[row][col]=digit;
                    if(solveSudoku(board,newr,newc))
                        return true;
                    board[row][col]='.';
                }
            }
        }
        else
        {
            if(solveSudoku(board,newr,newc))
                return true;
        }
        
    return false;

            
    }
    
    void solveSudoku(vector<vector<char>>& board) {
    solveSudoku(board, 0, 0);
    }
};