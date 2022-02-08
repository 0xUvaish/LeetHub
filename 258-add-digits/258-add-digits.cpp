class Solution {
public:
    int addDigits(int num) {
        if(num%10==num) 
            return num;
        
        while(num%10!=num){
            int sum=0;
            while(num>0){
                sum+=num%10;
                num/=10;
            }
            num=sum;
        }
        return num;
    }
};