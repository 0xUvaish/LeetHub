class Solution {
public:
    //M1: Brute Force
    int maximumSwap(int num) 
    {
        string s=to_string(num);
        int n=stoi(s);
        for(int i=0;i<s.size();i++)
        {
            for(int j=i+1;j<s.size();j++)
            {
                swap(s[i],s[j]);
                n=max(n,stoi(s));
                swap(s[i],s[j]);
            }
        }
        return n;
    }
};