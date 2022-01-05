class Solution {
public:
    int longestPalindrome(string s)
    {
         unordered_map<char,int> m;

 for(int i=0;i<s.size();i++)
 {
     
     if(m.count(s[i])>0)
         m[s[i]]++;
     else
         m[s[i]]=1;
 }
 
 unordered_map<char,int>::iterator it=m.begin();
 int x=0; 
    
 while(it!=m.end())
 {
     if((it->second)%2==1)
         x++;   
    it++;  
  } 

  if(x==0)
      return s.size();
        
  return s.size()-x+1;
    }
};