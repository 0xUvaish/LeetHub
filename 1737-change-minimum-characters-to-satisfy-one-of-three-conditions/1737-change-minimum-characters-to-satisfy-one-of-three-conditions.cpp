class Solution {
public:
    
    int count(string &a,string &b)
    {
        int ans=INT_MAX;
        
        for(char ch='b';ch<='z';ch++)
        {
            int cnt=0;
            
            for(char it:a)
                cnt += (it>=ch);
            for(char it:b)
                cnt += (it<ch);
            
            ans=min(ans,cnt);
        }
        
        return ans;
    }
    
    int minCharacters(string a, string b) 
    {
        int x=count(a,b);  //Condition 1
        int y=count(b,a);  //Condition 2
        
        int fans=INT_MAX;
        
        for(char c='a';c<='z';c++)   //Condition 3
        {
            int cnt=0;
            
            for(char it:a)
                cnt += (it!=c);
            for(char it:b)
                cnt += (it!=c);
            
            fans=min(fans,cnt);  
        }
        
     return min({x,y,fans});
    }
    
};