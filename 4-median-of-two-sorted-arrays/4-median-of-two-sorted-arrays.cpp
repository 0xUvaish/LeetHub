class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
        
    if(n>m)
        return findMedianSortedArrays(nums2, nums1);   
        
    int low=0;
    int high=n;
    
    //Cut1 & Cut2 are the first elements in right half
    while(low<=high)
    {
        int cut1 = (low + high)/2;
        int cut2 = (n+m+1)/2 - cut1;
        
        double l1 = cut1==0 ? INT_MIN: nums1[cut1-1];
        double l2 = cut2==0 ? INT_MIN: nums2[cut2-1];
        double r1 = cut1==n ? INT_MAX: nums1[cut1];
        double r2 = cut2==m ? INT_MAX: nums2[cut2];
        
        if(l1<=r2 && l2<=r1)
        {
            if((n+m)%2==0)
                return (max(l1,l2) + min(r1,r2))/2.0; 
            else
                return max(l1,l2);
        }
        
        else if(l1>r2)
            high = cut1-1;
        else
            low = cut1+1;
    }
    
    return 0.0; 
    }
};