class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(!(k%2) || !(k%5))
            return -1;
        
        auto r = 1, length = 1;
        while(true){
            r = r%k;
            if(!r)
                return length;
            r = r*10 + 1;
            length++;
        }
    }
};