class Solution {
public:
vector<int> findAnagrams(string s, string p) 
{
    unordered_map<char,int>m;
    for(int i=0;i<p.length();i++)
        m[p[i]]++;
    int count=m.size();
    vector<int>ans;
    int i=0,j=0;
    int n=s.length()-1;
    int k=p.length(); //window size
    while(j<=n)
    {
        if(m.find(s[j])!=m.end()) //if any character in s matches with the p string character
        {
            m[s[j]]--;
            if(m[s[j]]==0)
                count--;
        }
        if(j-i+1==k) //we might get an ans
        {
            if(count==0)
                ans.push_back(i);
            if(m.find(s[i])!=m.end())
            {
                m[s[i]]++;
                if(m[s[i]]==1)
                   count++;
            }
            i++;
        }
        j++;
    }
    return ans;
  }
};