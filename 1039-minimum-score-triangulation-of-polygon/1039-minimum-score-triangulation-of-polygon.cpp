class Solution {
public:
int t[101][101];

//Exactly MCM Code from GFG
int solve(vector<int>& arr, int i, int j)
{
    if(i+1==j)
        return 0;
    
    if(t[i][j] != -1)
        return t[i][j];
    
    int mn= INT_MAX;
    for(int k=i+1; k<j; k++)
    {
        int temp= solve(arr, i, k) + solve(arr, k, j) + 
            arr[i]*arr[k]*arr[j];
        
        if(temp<mn)
        t[i][j]=mn= min(mn, temp);
    }
    
    return t[i][j];
}


int minScoreTriangulation(vector<int>& values)
{
    
    memset(t,-1,sizeof(t));
    int i=0; 
    int j=values.size()-1;
    return solve(values, i, j);
}
    
};