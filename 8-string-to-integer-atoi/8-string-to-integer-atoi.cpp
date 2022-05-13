class Solution {
public:
    //Method 1: stringstream object
 int myAtoi(string s) 
 {
       stringstream abc(s);
        int x=0;
        abc>>x;
     return x;
    }
};