class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        string tmp(n,'a');
        
        for(int i=0;i<n;i++)
            tmp[indices[i]]=s[i];
        
        return tmp;
    }
};