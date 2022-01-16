class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int temp=INT_MAX,ans=INT_MIN,maxi=INT_MAX;
        vector<int> lseats(n,INT_MAX), rseats(n,INT_MAX);
        
        for(int i=0;i<n;i++)
        {
            if(seats[i]==1)
            {
                temp = i;
                lseats[i]=0;
            }
            else if(temp!=INT_MAX)
                lseats[i] = i-temp; 
        } 
        cout<<endl;
        temp = INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            if(seats[i]==1)
            {
                temp = i;
                rseats[i]=0;
            }
            else if(temp!=INT_MAX)
                rseats[i] = temp-i; 
                
            cout<<rseats[i]<<" ";
            maxi = min(lseats[i],rseats[i]);
            ans = max(ans, maxi);
        } 
        
        // for(int i =0;i<n;i++)
        // {
        //     maxi = min(lseats[i],rseats[i]);
        //     ans = max(ans, maxi);
        // }
        
        
return ans;
    }
};