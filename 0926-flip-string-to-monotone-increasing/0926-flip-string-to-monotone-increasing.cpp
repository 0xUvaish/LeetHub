class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count0 = 0 , count1 = 0 ;
        for(auto x : s)
            if(x == '0') count0 ++ ;

        int ans = count0 ;
        for(int i = 0 ;i < s.size() ; i++){
            if(s[i] == '1') count1++;
            else count0-- ;
            ans = min(ans , count0+count1) ;
        }
        return ans ;
    }
};