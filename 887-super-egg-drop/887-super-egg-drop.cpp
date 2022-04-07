class Solution {
public:
int t[101][10001];

int solve(int e,int f)
{
    if(f==1 || f==0 || e==1)
        return f;
    
    if(t[e][f]!=-1)
        return t[e][f];
    
    int ans=INT_MAX;
    int start=1,end=f;
    
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        int eggBreak = solve(e-1,mid-1);
        int eggNotBreak = solve(e,f-mid);
        int temp=1+max(eggBreak,eggNotBreak);  //Max because worst case
        ans=min(ans,temp);                     //Nut minimise no. of steps
        
        if(eggBreak<eggNotBreak)
            start=mid+1;
        else 
            end=mid-1;
    }
    
    return t[e][f]=ans;
}

int superEggDrop(int k, int n) 
{
    memset(t,-1,sizeof(t));
    return solve(k,n);
}
    
};