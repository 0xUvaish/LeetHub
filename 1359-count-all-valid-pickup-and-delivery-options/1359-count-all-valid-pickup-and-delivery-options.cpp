class Solution {
public:
    int countOrders(int n)
    {
        long j=3,prev=1,cur=1;
        for(int i=2;i<=n;i++){
            cur=(i*j*prev)%(1000000007);
            j+=2;
            prev=cur;
        }
        return cur;
    }
    
};