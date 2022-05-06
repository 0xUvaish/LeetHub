class Solution {
public:
    int MOD = 1000000007;
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        stack<int> st, st2;
        
        vector<int> right(n);
        vector<int> left(n);
        vector<long long> prefixSum(n);
        
        //Next Smaller on Right
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            
            if(st.empty())
                right[i]=n-1;
            else
                right[i]=st.top()-1;
            
            st.push(i);
        }
        
        
        //Next Smaller on Left
        for(int i=0;i<n;i++)
        {
            while(!st2.empty() && nums[st2.top()]>=nums[i])
                st2.pop();
            
            if(st2.empty())
                left[i]=0;
            else
                left[i]=st2.top()+1;
            
            st2.push(i);
        }
        
    //PrefixSum
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++)
            prefixSum[i] = nums[i] + prefixSum[i-1];
        
    
    //ActuaL Answer
        long long maxi = 0, temp;
        for(int i=0;i<n;i++)
        {
            int l = left[i];
            int r = right[i];
            long summ = prefixSum[r] - (l>0? prefixSum[l-1]:0);
            
            temp = (nums[i]*(summ));
            maxi = max(maxi, temp);
        }
        
    return maxi%MOD;
    }
};