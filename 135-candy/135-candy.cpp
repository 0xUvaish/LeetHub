class Solution {
public:
    //M1: Recursive
    //M2: PQ
    //M3: O(n)
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        //initialy give 1 candy to each
        vector<int> lr(n,1);
        vector<int> rl=lr;
        for(int i=1;i<n;i++)
            if(ratings[i]>ratings[i-1])
                lr[i]=lr[i-1]+1;
        
        for(int i=n-2;i>=0;i--)
            if(ratings[i]>ratings[i+1])
                rl[i]=rl[i+1]+1;
        
        int res=0;
        for(int i=0;i<n;i++)
            res+=max(lr[i],rl[i]);
        
        return res;
    }
};