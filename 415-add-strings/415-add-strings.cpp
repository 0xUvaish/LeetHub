class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        string ans="";
        int n1=num1.size()-1, n2=num2.size()-1,carry=0;
        
        while(n1>=0 || n2>=0)
        {
            int a=0,b=0;
            
            if(n1>=0)
            {
                a=num1[n1]-'0';
                n1--;
            }
            
            if(n2>=0)
            {
                b=num2[n2]-'0';
                n2--;
            }
            
            int sum=a+b+carry;
            
            if(sum>9)
            {
                carry=1;
                ans+=to_string(sum-10);
            }
            
            else
            {
                ans+=to_string(sum);
                carry=0;
            }
        }
        
        if(carry)
            ans+=to_string(carry); // if carry remains
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};