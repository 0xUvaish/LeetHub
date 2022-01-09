class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int p=1;
        int top=0,left=0,bottom=n,right=n;
        vector<vector<int>> v(n,vector<int>(n));
        
        while(top<bottom && left<right)
        {
            for(int k=left;k<right;k++)
                v[top][k]=p++;
            
            top++;
            
            for(int k=top;k<bottom;k++)
                v[k][right-1]=p++;
            
            right--;
            
            if(left<right)
            {
                for(int k=right-1;k>=left;k--)
                    v[bottom-1][k]=p++;
                bottom--;
            }
            
            if(top<bottom)
            {
                for(int k=bottom-1;k>=top;k--)
                    v[k][left]=p++;
                left++;
            }
        }
return v;
    }
};