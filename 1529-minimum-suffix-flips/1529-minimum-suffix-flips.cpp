class Solution {
public:
    //Continuous groups of 0s and 1s
int minFlips(string target) {

    int check=0,count=0;
    for(int i=0;i<target.length();i++)
    {
        if(target[i]-'0'!=check)
        {
            check=!check;
            count++;
        }
    }
    
    return count;
    }
};