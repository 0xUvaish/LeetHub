class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>ans(nums.size(),-1);
        int j=0;
        long long sum=0;  
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
          
            if(i-j+1>2*k){
              int avg = sum/(2*k+1);
              ans[i-k]=avg;
              sum-=nums[j];
              j++;
            }
        }
       
       return ans; 
    }
};