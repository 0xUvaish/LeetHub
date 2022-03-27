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
    
    void helper(string s ,int l ,int r,vector<string> temp,vector<vector<string>> &ans){
    
        if(l>r)
        {
            ans.push_back(temp);
			return;
        }
        
        for(int i = l;i<=r;i++)
        {
            if(check(s,l,i))
            {
              vector<string> dup = temp;
                dup.push_back(s.substr(l,i-l+1));
                helper(s,i+1,r,dup,ans);
            }
            
        }
        
        return;
    }
    
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        helper(s,0,s.size()-1,{},ans);
        return ans;
        
    }
};