class Solution {
public:
int findNumberOfLIS(vector<int>& nums) 
{
    int n=nums.size();
    
    if(n==0)
        return 0;
    
    vector<int> lis(n,1);//longest increasing subsequence array
    vector<int> count(n,1);//stores count of longest increasing subsequence
    int maxLis = 1;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            
            if(nums[j]<nums[i] && lis[i]<lis[j]+1)
            {
                lis[i]=lis[j]+1;
                count[i]=count[j];//count of j will extend to i
            }
            
            else if(nums[j]<nums[i] && lis[i]==lis[j]+1)
            {
                count[i]+=count[j];
            }
            maxLis = max(maxLis, lis[i]);
        }
    }
    
    int result=0;
    for(int i=0;i<n;i++)
    {
        if(maxLis==lis[i])
            result+=count[i];
    }
    
    return result;
}
    
};