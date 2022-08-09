class Solution {
public:
    //M1: Build entire triangle (Pascal's Traingle I problem)
    //M2: nC(r+1) = nCr * ((n-r)/(r+1)) where n is row, r is column
    
    vector<int> getRow(int rowIndex) 
    {
        vector<long long int> res(rowIndex+1,0);
        vector<int> realans(rowIndex+1,0);
        
        res[0]=1;
        for(int i=1;i<=rowIndex;i++)
           res[i] = ((rowIndex + 1 - i)*(res[i-1])) / i;
        
        for(int i=0;i<=rowIndex;i++)
            realans[i]=res[i];
        
    return realans;
    }
};