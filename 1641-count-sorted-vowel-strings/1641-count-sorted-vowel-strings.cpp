class Solution {
public:
 
//Method 1 - Recursion - 5^n Solution
int vowels(int index,int n)
{
    if(n==0)
        return 1;
    
    int count=0;
    for(int i=index;i<5;i++)
        count+=vowels(i,n-1);
    
    return count;
}
    
int countVowelStrings(int n)
{
    
    int count=0;
	for(int i=0;i<5;i++)
        count+=vowels(i,n-1);
    
    return count;
} 
    
    //Method 3 - PnC - Combination with repetition - !(n-1+r)/!(r)!(n-1) 
    // n = 5, r = n(n provided in question)
    // === ((n+1)*(n+2)*(n+3)*(n+4))/4
    // int countVowelStrings(int n) {
    //     return ((n+1)*(n+2)*(n+3)*(n+4))/24;
    // }
};