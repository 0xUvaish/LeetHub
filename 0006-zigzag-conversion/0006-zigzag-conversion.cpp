class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<string> vec(numRows, "");
        
        int ind = 0;
        int n = s.size();
        int i;
        
        while(ind<n)
        {
            i=0;
            while(i<numRows && ind<n)
                vec[i++] += s[ind++];
            
            i=numRows-2;
            while(i>=1 && ind<n)
                vec[i--] += s[ind++];
        }
        
        
        string ans="";
        for(auto x: vec)
            for(auto y: x)
                ans += y;
        
        return ans;
    }
};