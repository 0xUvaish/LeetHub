class Solution {
public:
int maxProduct(vector<string>& word) {

    int n = word.size();
     vector<vector<int>> v(n,vector<int>(26,0));
    for(int i=0;i<n;i++)
    {
        string str = word[i];
        for(int j=0;j<str.size();j++)
        {
            v[i][str[j]-'a'] =1;
        }
    }
    
    int ans =0;
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            flag = false;
            for(int k=0;k<26;k++)
            {
                if(v[i][k]&v[j][k])
                {
                    
                    flag = true;
                }
            }
            if(!flag)
            {
                
                int k = word[i].size()*word[j].size();
                ans = max(ans,k);
            }
        }
    }
    return ans;
}
};