class Solution {
public:
    vector<int>p;   //Child to Parent
    
    //Find by Path Compression
    int getP(int i)
    {
        return i==p[i]?p[i]:p[i]=getP(p[i]);
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        int n=s.size();
        vector<vector<int>>v(n);  //Parent to Child 
        
        for(int i=0;i<n;i++)
            p.push_back(i);
        
        for(auto&i:pairs)
        {
            int p1=getP(i[0]);
            int p2=getP(i[1]);
            
            if(p1!=p2)
                p[p2]=p1;
        }
        
        for(int i=0;i<n;i++)     //Parent to Child 
            v[getP(i)].push_back(i);
        
        for(auto&parent :v)
        {
            string ss="";
            
            for(auto&j :parent)
                ss+=s[j];
            
            sort(ss.begin(),ss.end());
            
            for(int id=0;id<parent.size();id++)
                s[parent[id]]=ss[id];
        }
        return s;
    }
};