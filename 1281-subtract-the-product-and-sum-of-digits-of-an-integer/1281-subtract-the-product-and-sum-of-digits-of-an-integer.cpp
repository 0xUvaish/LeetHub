class Solution {
public:
    int subtractProductAndSum(int n) {
        int temp = n;
        int sum=0,product=1, digit;
        while(temp!=0)
        {
            digit = temp%10;
            sum += digit;
            product *= digit;
            temp /= 10;
        }

    return product-sum;
    }
};