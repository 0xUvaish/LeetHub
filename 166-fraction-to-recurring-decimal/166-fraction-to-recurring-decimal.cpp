class Solution {
public:
    string fractionToDecimal(int num, int den) 
    {
        bool neg = (num<0)^(den<0) ? true: false;
        long long int n = num;
        long long int d = den;
        n = abs(n);
        d = abs(d);
        
        // (i) Before Decimal
        long long int tmp = n/d;
        string res = "";
        if(neg && n!=0)
         res += "-";

        res += to_string(tmp);
        n %= d;
        if(n==0)
            return res;
        
        //(ii) Decimal
        res += ".";
        
        // (iii) After Decimal part
        unordered_map<long long int, int> mp; // mapping from remainder to size of string
        while(n!=0)
        {
            if(mp.find(n)==mp.end())
                mp[n] = res.size();
            else if(mp.find(n)!=mp.end())     // repeatition found
            {
                res.push_back(')');
                res.insert(mp[n],"(");
                break;
            }
            
            n *= 10;
            res += to_string(n/d);
            n %= d;
        }
        return res;
    }
};