class Solution {
public:
 string minWindow(string s, string t)
 {
         int r=s.size(),ans=INT_MAX,idx=-1;
         unordered_map<char, int> m;
         for(auto i: t)
             m[i]++;
         int cnt=m.size(),j=0;
     
         for(int i=0; i<r; i++)
         {
             if(--m[s[i]]==0)cnt--;
             while(cnt==0)
             {
                 int templength=i-j+1;
                 if(templength<ans)
                 {
                     ans=templength;
                     idx=j;
                 }
                 if(++m[s[j]]==1)
                     cnt++;
                 j++;
             }
         }
         if(idx==-1)
             return "";
     
return s.substr(idx,ans);
         
     }
};