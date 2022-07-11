class Solution {
public:
    int getSum(int a, int b) {

        int sum=a^b;
        unsigned int carry=a&b;

        while(carry != 0)
        {
            carry=carry << 1;
            int prev_sum=sum;
            
            sum=prev_sum^carry;
            carry=prev_sum & carry;
        }

        return sum;
    }
};