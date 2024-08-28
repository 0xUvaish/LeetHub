class Solution {
public:
 string minWindow(string s, string t)
 {
         int r=s.size(),ans=INT_MAX,idx=-1;
         unordered_map<char, int> m;
         for(auto i: t)
             m[i]++;
     
         int cnt=m.size(),i=0;
     
         for(int j=0; j<r; j++)
         {
             if(--m[s[j]]==0)
                 cnt--;
             
             while(cnt==0)
             {
                 int templength=j-i+1;
                 if(templength<ans)
                 {
                     ans=templength;
                     idx=i;
                 }
                 if(++m[s[i]]==1)
                     cnt++;
                 i++;
             }
         }
     
         if(idx==-1)
             return "";
     
    return s.substr(idx,ans);
         
     }
};