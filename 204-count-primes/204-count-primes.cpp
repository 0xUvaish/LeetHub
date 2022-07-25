class Solution {
public:
    //Sieve of Erastothenes O(nlog(log(n)))
    int countPrimes(int n) 
    {
        bool arr[n+1];
        memset(arr,1,sizeof(arr));
        
        for(int i=2;i*i<=n;i++)
            if(arr[i])
                for(int j = i*2;j<=n;j+=i)
                    arr[j] = 0;
        
        int count = 0;
        for(int i=2;i<n;i++)
            if(arr[i]==1)
                count++;
        
        return count;
    }
};