class Solution {
public:
    
    void fun(int idx,vector<int>& a,vector<int>& ds,vector<vector<int>>& ans){
        
        ans.push_back(ds);
        for(int i=idx;i<a.size();i++)
        {
            if(i!=idx && a[i]==a[i-1])
                continue;
            
            ds.push_back(a[i]);
            fun(i+1,a,ds,ans);
            ds.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(a.begin(),a.end());
        fun(0,a,ds,ans);
        
        return ans;
    }
};