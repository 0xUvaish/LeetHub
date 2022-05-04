class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
   int n = digits.size();

    for(int i=n-1; i>=0; i--)
    {
        if(digits[i] != 9)
        {
            digits[i]++;
            return digits;
        }
                
        else if(digits[i] == 9 and i > 0) 
            digits[i] = 0;
        
        else if(digits[i] == 9 and i == 0)
        {
            digits[i] = 0;
            digits.emplace(digits.begin(), 1);
            return digits;
        }

     }
        
    return digits;
    }
};