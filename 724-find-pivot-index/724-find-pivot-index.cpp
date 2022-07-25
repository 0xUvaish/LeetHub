class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int n = nums.size();
        vector<int> leftS(n,0), rightS(n,0);
        int left=0,right=0;
        
        for(int i=0;i<n;i++)
        {
            left += nums[i];
            leftS[i] = left;
        }
        
        for(int i=n-1;i>=0;i--)
        {
            right += nums[i];
            rightS[i] = right;            
        }
        
        for(int i=0;i<n;i++)
        {
            int lsum = (i==0 ? 0: leftS[i-1]);
            int rsum = (i==n-1 ? 0: rightS[i+1]);
            if(lsum==rsum)
                return i;
        }
        
    return -1;
    }
};