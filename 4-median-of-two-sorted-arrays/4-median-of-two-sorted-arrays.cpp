class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        
        vector<int> v;
        v=nums1;
        v.insert(end(v), begin(nums2), end(nums2));
        
        sort(v.begin(),v.end());
        int k=v.size();
        if((n+m)%2==0){
            
            return (v[(k-1)/2] + v[(k+1)/2])/2.00000 ;
            
        }
           
            return v[(k-1)/2];
            
        
    }
};