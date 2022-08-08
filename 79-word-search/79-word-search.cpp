class Solution {
public:
  bool result = false;
    bool visited[6][6];
    void solve(vector<vector<char>>& board, string& word,int i,int j,int idx)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] == true || result == true || board[i][j] != word[idx])
           return;
        
        if(idx == word.size()-1)
            result = true;
        
        visited[i][j] = true;
        solve(board,word,i+1,j,idx+1);
        solve(board,word,i-1,j,idx+1);
        solve(board,word,i,j+1,idx+1);
        solve(board,word,i,j-1,idx+1);
        visited[i][j] = false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        memset(visited,false,sizeof(visited));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                    solve(board,word,i,j,0);
                
                if(result == true)
                    return true;
            }
        }
        return false;
    }
};