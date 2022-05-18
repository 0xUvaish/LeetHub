class Solution {
public:
    int nextGreaterElement(int n) {
        int num_digits=log10(n);
       long long ans=0;
        vector<int>digits(num_digits+1);
        int i=num_digits;
        
        while(n>0)
        {
            int temp=n%10;
            n=n/10;
            digits[i]=temp;
            --i;
        }
        
        for( i=num_digits;i>0;--i)
        {
            if(digits[i-1]<digits[i])
                    break;
        }
        if(i==0)
            return -1;
        
        int temp=i-1;
        //Now finding just greater element
        i=num_digits;
        while(digits[i]<=digits[temp])
                --i;
        swap(digits[i],digits[temp]);
        reverse(digits.begin()+temp+1,digits.end());
        
        
        for(i=num_digits;i>=0;--i)
        {
           
            long long power=pow(10,num_digits-i);
            ans=ans+digits[i]*power;
            
        }
        if(ans>INT_MAX)
                return -1;
       
        
        
        return ans; 
    }
};