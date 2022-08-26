class Solution {
public:
    bool reorderedPowerOf2(int n)
    {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        for(int i = 0; i < 30; ++i)
        {
            string s2 = to_string(1 << i);
            sort(s2.begin(), s2.end());
            
            if(s == s2) 
                return true;
        }
		return false;
    }
};