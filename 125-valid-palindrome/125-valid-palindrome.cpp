class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int h = s.size() - 1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 65 && s[i] <= 90){
                s[i] = s[i] - 'A' + 'a';
            }
        }
        
        while(l < h)
        {
            while(!isalnum(s[l]) && l<h)
                l++;
            
            while(!isalnum(s[h]) && l<h)
                h--;
            
            if(s[l] != s[h])
                return false;
            l++; h--;
        }
        return true;
    }
};