class Solution {
public:
    
    string fn(string s){
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0') s[i]='1';
            else s[i]='0';
        }    
        reverse(s.begin(), s.end());
        return s;
    }
    
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=2; i<=n; i++){
            string rev = fn(s);
            s = s + "1" + rev;
        }
        return s[k-1]; 
    }
};
