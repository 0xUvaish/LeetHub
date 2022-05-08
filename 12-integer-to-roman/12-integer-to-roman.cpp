class Solution {
public:
    string intToRoman(int num) 
    {
        const vector<vector<string>> intToRoman = 
        {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},  //1-digit
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},  //2-digirs
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},  //3-digits
            {"", "M", "MM", "MMM", "MMMM"}                                 //4-digits
        };
        
        string result;
        int row=0, col;
        
        while (num > 0)
        {
            col = num%10;
            num /= 10;
            
            result = intToRoman[row++][col] + result;
        }
        
        return result;
    }
};