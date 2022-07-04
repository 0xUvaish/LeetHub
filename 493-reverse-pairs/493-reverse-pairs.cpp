class Solution {
public:
    void merge(vector<int>&nums,int low,int mid,int high,int &c)
    {
        int i=low;
        int j=mid+1;
        
        vector<int>temp(high-low+1);
        
        //We cannot directly merge alongwith counting,,,this is why it is Hard Problem
        while(i<=mid and j<=high)
        {
            if(nums[i]>2*1ll*nums[j])
            {
                c += (mid-i+1);  ///answer line
                j++;
            }
            else
            {
                i++;
            }
        }
        
        
        i=low;
        j=mid+1;
        int k=0;
        while(i<=mid and j<=high)
        {
            if(nums[i]<nums[j])
                temp[k++]=nums[i++];
            else
                temp[k++]=nums[j++];
        }
        
        while(i<=mid)
            temp[k++]=nums[i++];
        
        while(j<=high)
            temp[k++]=nums[j++];
        
        for(i=low;i<=high;i++)
            nums[i]=temp[i-low];

    }
    
    void mergeSort(vector<int>&nums,int low,int high,int &c)
    {
        if(low<high)
        {
            int mid=(low+high)/2;
            mergeSort(nums,low,mid,c);
            mergeSort(nums,mid+1,high,c);
            
            merge(nums,low,mid,high,c);
        }
    }
    
    int reversePairs(vector<int>& nums) 
    {
        
        int n=nums.size();
        int c=0;
        mergeSort(nums,0,n-1,c);
        return c;
    }
};