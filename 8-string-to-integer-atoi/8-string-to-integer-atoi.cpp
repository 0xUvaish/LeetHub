class Solution {
public:
    //Method 1: stringstream object
 // int myAtoi(string s) 
 //   {
 //       stringstream abc(s);
 //        int x=0;
 //        abc>>x;
 //     return x;
 //    }
    
    //Method2: O(n) TC, O(1) SC
int myAtoi(string s)
{
    
    int leadSpace= 0;
    for(int i=0; i<s.length(); i++)
        if(s[i]==' ')
            leadSpace++;
        else
            break;
    
    s.erase(0, leadSpace);
    
    if(s.length()== 0)
        return 0;
    
    int sign= 1;
    int start= 0;
    
    if(s[0]== '-'){
        sign= -1;
        start= 1;
    }
    else if(s[0]== '+'){
        sign= 1;
        start= 1;
    }
    

    long long res= 0;
    
    for(int i= start; i<s.length(); i++)
    {
        if(!(s[i]>= '0' && s[i]<= '9'))
            return res* sign;
        
        res= res*10 + int(s[i]- '0');
        
        //Range is given
        if(res*sign <= INT_MIN)
            return INT_MIN;
        else if(res*sign >= INT_MAX)
            return INT_MAX;
    }
    
    return res*sign;
    }
};