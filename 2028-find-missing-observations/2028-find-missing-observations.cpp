class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int miss, tot=0,m=rolls.size();
                vector<int> res;
        for(auto x:rolls)
            tot += x;
        if(tot > (rolls.size()+n)*mean)
            return res;
        miss = (m+n)*mean - tot;
        
        int k = miss/n;
        int rem = miss%n;
        if(k<1 || k>6)
            return res;
;
        if(miss > n*6)
            return res;
        int mn=1;
        while(n--)
        {
            res.push_back(k + (mn<=rem));
            rem--;
        }
        
    return res;
    }
};