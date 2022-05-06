class Solution {
public:
    //Method 1: Sorting + Space --> Insert greater no. from i=1 till the end of array and then for i=0 till the end
    void wiggleSort(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>v(nums.begin(), nums.end());
        
        sort(v.begin(),v.end());
        
        int j=n-1;
        for(int i=1;i<n;i+=2)
            nums[i]=v[j--];
        
        for(int i=0;i<n;i+=2)
            nums[i]=v[j--];
        
    }
};