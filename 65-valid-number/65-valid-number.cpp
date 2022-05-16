class Solution {
public:
    
bool isNumber(string s) 
 {
    int i=0, n = s.length();
    
    while(i<n && s[i]==' ')
        i++;
    if(i<n && (s[i]=='+' || s[i]=='-'))
        i++;
    
    bool isNumeric = false;
    while(i<n && (s[i]>='0' && s[i]<='9'))
    {
        i++;
        isNumeric = true;
    }
    
    if(i<n && s[i]=='.')
    {
        i++;
        while(i<n && (s[i]>='0' && s[i]<='9'))
        {
            i++;
            isNumeric = true;
        }
    }
    
    if(i<n && isNumeric && (s[i]=='e' || s[i]=='E'))
    {
        i++;
        
        if(i<n && (s[i]=='+' || s[i]=='-'))
            i++;
        
        isNumeric = false;
        while(i<n && (s[i]>='0' && s[i]<='9'))
        {
            i++;
            isNumeric = true;
        }
    }
    
    
    while(i<n && s[i]==' ')
        i++;
    
    return (isNumeric&& i==n);
    
 }
};