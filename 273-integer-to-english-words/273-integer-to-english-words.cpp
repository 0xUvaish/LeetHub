class Solution {
public:
    string onedigit(int n)
    {
        if(n==0)
            return "";
        
        string word[]={"One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
        return word[n-1];
    }
    
    string twodigit(int n)
    {
        string ans="";
        
        if(n<10)
            ans+=onedigit(n);
        
        else if(n>19)
        {
            string word[]={"Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
            ans+=word[n/10-2]+onedigit(n%10);
        }
        else
        {
            string word[]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
            int in=n%10;
            ans+=word[in]+" ";
        }
        
        return ans;
    }
    
    string threedigit(int n)
    {
        string ans="";
        
        int hundred=n/100;
        if(hundred!=0)
            ans+=onedigit(hundred)+"Hundred ";
        
        int tens=n%100;
        if(tens!=0)
            ans+=twodigit(tens);
        
        return ans;
    }
    
    string numberToWords(int n)
    {
        
        if(n==0)
            return "Zero";
        
        string ans="";
        
        int billion=n/1e9;
        n=n%1000000000;
        if(billion!=0)
            ans+=threedigit(billion)+"Billion ";
        
        int million=n/1e6;
        n=n%1000000;
        if(million!=0)
            ans+=threedigit(million)+"Million ";
        
        int thousand=n/1e3;
        n=n%1000;
        if(thousand!=0)
            ans+=threedigit(thousand)+"Thousand ";
        
        int hundred=n;
        ans+=threedigit(hundred);
        
        ans.pop_back();
        return ans;
    }
};