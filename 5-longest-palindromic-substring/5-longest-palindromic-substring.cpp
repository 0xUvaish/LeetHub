class Solution {
public:
    void checkPalindrome(string &s, int left, int right, int &maxLen, int &index){

        while(left>=0 && right<s.length() && s[left]==s[right]){
            if(maxLen<(right-left+1) ){
                maxLen = right-left+1;
                index = left;
            }
            left--; 
            right++;
        }
    }
    string longestPalindrome(string s) {
        int maxLen=1;
        int index=0;
        int left,right;
        
        for(int i=0;i<s.length();i++){
            checkPalindrome(s,i,i,maxLen,index);
            checkPalindrome(s,i,i+1,maxLen,index);
        }
       
        return s.substr(index,maxLen);
    }
};