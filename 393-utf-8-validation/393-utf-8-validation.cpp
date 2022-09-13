class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        for (int i = 0, rem = data.size(); rem > 0; i++, rem--) {
                
            int d = data[i];
            
            if ((d & 0b11111000) == 0b11110000) {                
                if (!validRem(data, i, rem, 3)) return false;
                
            } else if ((d & 0b11110000) == 0b11100000) {
                if (!validRem(data, i, rem, 2)) return false;
                
            } else if ((d & 0b11100000) == 0b11000000) {                
                if (!validRem(data, i, rem, 1)) return false;
                
            } else if (d & 0b10000000) return false;
                
        }
        
        return true;
    }
    
    inline bool validRem(vector<int>& data, int &i, int &rem, int n) {
        
        if (rem <= n) return false;
        
        while (n-- > 0) {
            i++, rem--;
            if ((data[i] & 0b11000000) != 0b10000000)
                return false;
        }
        
        return true;
    }
};