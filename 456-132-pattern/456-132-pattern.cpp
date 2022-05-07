class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> minval(n);
        minval[0] = nums[0];
        
        //Prefix Min
        for(int i = 1; i<n; i++)
           minval[i] = min(nums[i], minval[i-1]);  
        
        
        stack<int> st;
        for(int j = n - 1; j>=0; j--)
        {
            while(!st.empty() && st.top() <= minval[j])       //Compare 1 or prefixMin with 2 of Stack
                st.pop();
            
            if(!st.empty() && st.top() < nums[j])             //Compare current 3 with 2 of Stack
                return true;
            
            st.push(nums[j]);
        }
        
        return false;
    }
};