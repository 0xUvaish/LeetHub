class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
       int n=arr.size();
        int dec=0,inc=0;
        if(n<3)
            return false;
        
        for(int i=1;i<n;i++)
        {
            if(arr[i]<arr[i-1])
                dec++;
            else if(arr[i]>arr[i-1])
                inc++;
            else
                return false;
            
            if(dec>0 && arr[i]>arr[i-1])
                return false;
           
        }
        
    if(dec==0 || inc==0)
        return false;
        
    return true;
            
    }
};