class Solution {
public:
    bool detectCapitalUse(string word) {
        int c=0,s=0,flag=0,n=word.size();
        for(int i=0;i<n;i++)
        {
            if(word[i]>='A' && word[i]<='Z')
            {
                c++;
                flag = i==0;
            }
    
            else if(word[i]>='a' && word[i]<='z')
                s++;
        }
        
        if(c==n)
            return true;
        else if(s==n)
            return true;
        else if(flag==1)
            return true;
        
        else return false;
    }
};