// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    //Without using rand7()
//     int g=0;
//     int rand10() {
//         g++;
//         if(g%10==0)
//             return 10;
        
//         return g%10;
//     }
    
    //Using rand7()
    int tmp=0;
    int rand10()
    {
        int k = rand7() + tmp;
        if(k==10)
            tmp=0;
        else 
        {
            k=k%10;
            tmp=k;
        }
        return k;
    }
};