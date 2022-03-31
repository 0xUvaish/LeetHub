class Solution {
public:

//Next smaller
    vector<int> nextsmaller(vector<int>& nums,int n){
        stack<int>st;
         st.push(-1);
        vector<int>ans(n);
        for(int i=nums.size()-1;i>=0;i--)
        {
           
            while(st.top()!=-1 && nums[st.top()]>=nums[i])
                st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    
//Prev smaller
     vector<int> prevsmaller(vector<int>& nums,int n)
     {
        stack<int>st;
          st.push(-1);
        vector<int>ans(n);
        for(int i=0;i<nums.size();i++)
        {
           
            while(st.top()!=-1 && nums[st.top()]>=nums[i])
                st.pop();
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    
    
    int largestRectangleArea(vector<int>& nums) 
    {
        int n=nums.size();
        int maxo=0;
        
        vector<int>ps(n);
        ps=prevsmaller(nums,n);
        
        vector<int>ns(n);
        ns=nextsmaller(nums,n);
        
        for(int i=0;i<nums.size();i++)
        {
            if(ns[i]==-1)
                ns[i]=n;
            
            int x=(ns[i]-ps[i]-1)*nums[i];
            
            maxo=max(maxo,x);
        }
        
        return maxo;
    }
};