class Solution {
public:
    int repeatedStringMatch(string a, string b)
    {
        string s = a+a;
        int n = s.size(), m = b.size();
        
        vector<int>LPS(m, 0);
        for(int i = 1; i < m; i++)
        {
            int j = LPS[i-1];
            while(j > 0 && b[i] != b[j])
                j = LPS[j-1];
            if(b[i] == b[j])
                LPS[i] = j+1;
            else
                LPS[i] = 0;
        }
        
        int i = 0, j = 0, cnt = 0;
        while(j < m)
        {
            if(i%n == n-1) 
                cnt++;
            if(s[i%n] == b[j])
            {
                i++, j++;
                continue;
            }
            if(cnt != 0)
                return -1;
            if(j == 0) 
                i++;
            else
                j = LPS[j-1];
        }
        
        if(i%n == 0) 
            return 2*cnt;
        else if(i%n <= n/2) 
            return 2*cnt+1;
        else 
            return 2*cnt+2;
    }
};