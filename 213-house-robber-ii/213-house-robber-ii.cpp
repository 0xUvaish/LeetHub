class Solution {
public:
    vector<int> dpstart; //house 1 to N-1
    vector<int> dpend; //house 2 to N
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1) 
            return nums[0];
        
        dpstart.resize(n,0);
        dpend.resize(n+1,0); 
        
        dpstart[0]=0;
        dpstart[1]=nums[0];
        
        dpend[1]=0;
        dpend[2]=nums[1]; 
        
        for(int i=2;i<=n-1;i++)
            dpstart[i]=max(dpstart[i-1],dpstart[i-2]+nums[i-1]);
        
        for(int i=3;i<=n;i++)
            dpend[i]=max(dpend[i-1],dpend[i-2]+nums[i-1]);
        
    return max(dpstart[n-1],dpend[n]);
    }
};