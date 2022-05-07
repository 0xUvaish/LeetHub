class Solution {
public:
bool check(string s , int l ,int r)
{
        while(l<=r)
        {
           if(s[r]!=s[l])
               return false;
            l++;
            r--;
        }
        return true;
    }
    
    void helper(string s ,int l ,int n,vector<string> temp,vector<vector<string>> &ans){
    
        if(l==n)
        {
            ans.push_back(temp);
			return;
        }
        
        for(int i=l;i<n;i++)
        {
            if(check(s,l,i))
            {
                temp.push_back(s.substr(l,i-l+1));
                helper(s,i+1,n,temp,ans);
                temp.pop_back();
            }
            
        }
    }
    
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        
        vector<vector<string>> ans;
        vector<string> temp;
        
        helper(s,0,n,temp,ans);
        return ans;
        
    }
};