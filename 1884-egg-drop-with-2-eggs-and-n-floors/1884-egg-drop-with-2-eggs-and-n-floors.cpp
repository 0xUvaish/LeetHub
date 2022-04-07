class Solution {
public:
    int twoEggDrop(int n)
    {
        return ceil((-1+sqrt(1+8*n))/2);
    }
    
    /*
    
    1
    2 2
    3 3 3
    4 4 4 4
    5 5 5 5 5
    
    For n answer will be x
    
    and n = x*(x+1)/2
    therefore equation
    
    x^2 + x - 2n = 0
    a=1,b=1,c=-2n
    Using Quadratic formula
        x = (-b + sqrt(b^2 - 4ac))/2a
        
    */
};