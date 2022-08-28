class Solution {
public:
    
    //Sol 1: Insertion Sort O(n^3) Sol
//     vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {

//     for(int t=1;t<mat.size();t++)
//     {
//         for(int i=1;i<mat.size();i++)
//         {
//             for(int j=1;j<mat[0].size();j++)
//             {
//                 if(mat[i][j]<mat[i-1][j-1])
//                     swap(mat[i][j],mat[i-1][j-1]);
//             }
//         }
//     }
//     return mat;
//     }
    
    
    //Sol2: Priority Queue
    void diagonalSorter(int i,int j,vector<vector<int>>&mat)
    {
        int m=mat.size(),n=mat[0].size();
        priority_queue<int>arr;
        
        while(i<m && j<n)
        {
            arr.push(mat[i][j]);
            i++,j++;
        }
        i--,j--;
		
        while(i>=0 && j>=0)
        {
            mat[i][j]=arr.top();
            arr.pop();
            i--,j--;
        }
    }
    
    vector<vector<int>> diagonalSort(vector<vector<int>> mat)
    {
        int m=mat.size(),n=mat[0].size();
        
        for(int i=m-1,j=0; i>=0 && j<n; i==0?j++:i--)
            diagonalSorter(i,j,mat);
        
        return mat;
    }
};