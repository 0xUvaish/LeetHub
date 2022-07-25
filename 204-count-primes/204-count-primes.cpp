class Solution {
public:
    int countPrimes(int n) 
    {
        bool arr[n+1];
        memset(arr,0,sizeof(arr));
        
        for(int i=2;i*i<=n;i++)
            if(!arr[i])
                for(int j = i*2;j<=n;j+=i)
                    arr[j] = 1;
        
        int count = 0;
        for(int i=2;i<n;i++)
            if(arr[i] == 0)
                count++;
        
        return count;
    }
};