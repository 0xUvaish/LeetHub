class Solution {
public:
int findNumberOfLIS(vector<int>& nums) 
{
    int n=nums.size();
    
    if(n==0)
        return 0;
    
    vector<int> lis(n,1);//longest increasing subsequence array
    vector<int> count(n,1);//stores count of longest increasing subsequence
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            
            if(nums[i]>nums[j] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
                count[i]=count[j];//count of j and i are equal
            }
            
            else if(lis[i]==lis[j]+1)
            {
                count[i]+=count[j];
            }
        }
    }
    int maximum=INT_MIN;
    for(int i=0;i<n;i++)//calculating maximum in lis array
    {
        maximum=max(maximum,lis[i]);
    }
    int result=0;
    for(int i=0;i<n;i++)
    {
        if(maximum==lis[i])
            result+=count[i];
    }
    return result;
}
    
};