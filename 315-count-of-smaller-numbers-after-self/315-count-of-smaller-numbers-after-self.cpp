class Solution {
   
    vector<int> res;
    
    void merge(vector<pair<int, int>> &nums, int left, int mid, int right, vector<pair<int,int>> &temp)
    {        
        int i = left, k = left, j = mid+1;
        
        // sorting in descending order
        while(i <= mid && j <= right)
        {
            if(nums[i].first <= nums[j].first)
                temp[k++] = nums[j++];
            else
            {
			    // if cur ele is greater than ele in right sub-array, we need to add this count
                res[nums[i].second] += right - j + 1;   
                temp[k++] = nums[i++];
            }
        }
        
        while(i <= mid) 
            temp[k++] = nums[i++];
        while(j <= right) 
            temp[k++] = nums[j++];
        
        for(int i = left; i <= right; i++)
            nums[i] = temp[i];
    }
    
    void mergeSort(vector<pair<int, int>> &v, int left, int right,vector<pair<int,int>> &temp)
    {
        if(right > left)
        {
            int mid = (left + right) >> 1;
            
            mergeSort(v, left, mid, temp);
            mergeSort(v, mid+1, right, temp);
            
            merge(v, left, mid, right, temp);
        }
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        int n = nums.size();
        res = vector<int>(n, 0);
        
        vector<pair<int, int>> v(n), temp(n);
        for(int i = 0; i < n; i++)   
            v[i] = {nums[i], i};
        
        mergeSort(v, 0, n-1, temp);
        
        return res;
    }
    
};