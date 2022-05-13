class Solution {
public:
 int myAtoi(string s) 
 {
       stringstream abc(s);
        int x=0;
        abc>>x;
        
        return x;
    }
};