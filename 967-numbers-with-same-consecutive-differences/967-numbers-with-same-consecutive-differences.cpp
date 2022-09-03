class Solution {
public:
    void helper(int n, int k, string temp, vector<string> &res)
    {
        
        int lim = 0, size = temp.size();
        if(n==size)
        {
            res.push_back(temp);
            return;
        }
        
        if(size==0) 
            lim += 1;
        
        for(int i = lim; i <= 9; ++i) 
        {
            if(size == 0) 
            {  
                temp += (char)(i + '0');
                helper(n, k, temp, res);
                temp.pop_back();
            }
            else if(size != 0)
            {
                char lastchar = temp.back();
                if(abs((char)(i+'0') - lastchar) == k)
                {
                    temp += (char)(i + '0');
                    helper(n, k, temp, res);
                    temp.pop_back();
                }
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        
        vector<string> res;
        vector<int> finalres; 
        
        helper(n, k, "", res);
        
        for(auto x : res) 
            finalres.push_back(stoi(x));
        
        return finalres;
    }
};