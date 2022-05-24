class Solution {
public:
vector<vector<string>> ans;
    bool issafe(vector<string> &v,int i,int j)
    {
        
        int x=i-1;
        while(x>=0)
        {
            if(v[x][j]=='Q')
                return false;
            x--;
        }
        
        x=i-1;
        int y=j-1;
        while(x>=0 && y>=0)
        {
            if(v[x][y]=='Q')
                return false;
            x--;
            y--;
        }
        
        x=i-1;
        y=j+1;
        while(x>=0 && y<v.size()){
            if(v[x][y]=='Q')
                return false;
            x--;
            y++;
        }
        
        return true;
            
    }
    void nqueen(vector<string> &v,int i,int n)
    {
        if(i==n)
        {
            ans.push_back(v);
            return;
        }
        
        for(int c=0;c<n;c++)
        {
            if(issafe(v,i,c))
            {
                v[i][c]='Q';
                nqueen(v,i+1,n);
                v[i][c]='.';
            }
        }
            
    }
    
    
    int totalNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++)
            s+=".";
        
        vector<string> v(n, s);

        nqueen(v,0,n);
        
        return ans.size();
    }
};