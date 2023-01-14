class Solution {
public:
    char findParent(char node,unordered_map<char,char>&parent)
    {
        if(node==parent[node])
        {
            return node;
        }
        return parent[node]=findParent(parent[node],parent);
    }
    void lexUnion(char a,char b,unordered_map<char,char>&parent)
    {
        char u=findParent(a,parent);
        char v=findParent(b,parent);
        if(u<v)
        {
            parent[v]=u;
        }
        else
        {
            parent[u]=v;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        unordered_map<char,char>parent;
        for(char p='a';p<='z';p++)
        {
            parent[p] = p;
        }
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                lexUnion(s1[i],s2[i],parent);
            }
        }
        for(auto it:parent)
        {
            cout<<it.first<<" parent is "<<it.second<<endl;
        }
        string output="";
        for(auto it:baseStr)
        {
            output+=findParent(it,parent);
        }
        return output;
    }
};