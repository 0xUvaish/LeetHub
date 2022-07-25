class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        int m=INT_MAX,n=strs.size();
        
        for(auto& i:strs)
            if(m>i.size())
                m=i.size();           //smallest length of string
        
            string op="";
        
        for(int j=0;j<m;j++)        //for each character of smallest length string
        {
            int c=0;
            for(int i=0;i<n-1;i++)    //checking in each word
            {
                if(strs[i][j]==strs[i+1][j])
                    c++;
                else 
                    break;
            }
            
            if(c==n-1)
                op+=strs[0][j];
            else 
                break;
        }
        
        return op;
    }
};