class Solution {
public:
string getSmallestString(int n, int k) {
        string res(n, 'a');
        k = k - n;
        for(int i = n - 1; i >= 0; i--) 
        {
            if(k <= 0) 
                break;
            
            res[i] = 'a' + min(25, k);
            k = k - min(25, k);
        }
        
        return res;
    }
};