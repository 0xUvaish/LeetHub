class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
       
        int m=mat.size();
        int n=mat[0].size();
        int k=m+n-1; //Run for n col then m-1 rows from vertical
        vector<int>v;
        
        for(int i=0;i<k;i++)
        {
            if(i%2==1)
            {
                int x=0,y=i;
                while(x<=i and y>=0)
                {
                    if(x<m and y<n) 
                        v.push_back(mat[x][y]);
                    x++;
                    y--;
                }
            }
            else
            {
                int x=i,y=0;
                while(x>=0 and y<=i)
                {
                    if(x<m and y<n) 
                        v.push_back(mat[x][y]);
                    x--;
                    y++;
                }
            }
        }
        return v;
    }
};