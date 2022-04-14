class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    
        int n = arr.size();
        int start=0;
        int end =n-1;
        int peak =0;
    
      while (start<end)
      {
            int  middle=start+(end-start)/2;
        
            if (arr[middle]<arr[middle+1])
                start=middle+1;
            else
                end=middle;
        
      }
    
   return start;        
    }
};