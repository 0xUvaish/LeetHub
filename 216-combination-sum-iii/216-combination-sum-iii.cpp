class Solution {
    
public:
    
    vector<vector<int>>res ;
    void helper(vector<int>& candidates, int k,int n,vector<int>&ans,int ind)
    {
        int N = ans.size();

        if(n<0)
            return;

        if( N > k )
            return;

        if( 0 == n && N == k )
        {
            res.push_back(ans);
            return;
        }
        
        for(int i=ind;i<candidates.size();i++)
        {
            if( candidates[i] > n )
                break;

            ans.push_back(candidates[i]);
            helper(candidates,k,n-candidates[i],ans,i+1);
            ans.pop_back();

        }
        
        return;
    }
    
    vector<vector<int>> combinationSum3(int k , int n) {
        
        vector<int>temp;
        vector<int>list = {1,2,3,4,5,6,7,8,9};

        helper(list,k,n,temp,0);
        
        return res;
    }
};