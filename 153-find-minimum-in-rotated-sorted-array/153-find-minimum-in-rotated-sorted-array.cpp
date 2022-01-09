class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int l = 0;
        int r = nums.size()-1;
        int minN = nums[0];
        int mid, leftNum, rightNum, midNum;
        while(l<r){
            mid = l + (r - l) / 2;
            leftNum = nums[l];
            rightNum = nums[r];
            midNum = nums[mid];
            minN = min({leftNum, rightNum, midNum, minN});
            
            if(midNum > rightNum)
                l = mid+1;
            
            else
                r = mid-1;
        }
        
return minN;
    }
};