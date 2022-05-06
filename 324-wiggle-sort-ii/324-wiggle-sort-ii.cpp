class Solution {
public:
    //Method 1: Sorting + Space --> Insert grrater no. from i=1 till the end of array and then for i=0 till the end
    void wiggleSort(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<int> temp(n);
        
        int i = 1, j = n-1;
        while(i<n)
        {
            temp[i] = nums[j];
            i+=2;
            j--;
        }
        
        i = 0;
        while(i<n)
        {
            temp[i] = nums[j];
            i+=2;
            j--;
        }
        
        for(int it=0; it<n; it++)
            nums[it] = temp[it];
    }
};