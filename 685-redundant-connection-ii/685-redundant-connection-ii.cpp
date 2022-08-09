class DSU
{
    public:
    vector<int>p;
    DSU(int n){
        p.resize(n,-1);
        for(int i=0;i<n;i++){
            make_set(i);
        }
    }
    int find(int a){
        if(p[a]==a)return a;
        p[a] = find(p[a]);
        return p[a];
    }
    void union_set(int a,int b){
        a = find(a);
        b = find(b);
        if(a==b)return;
        p[b] = a;
    }
    void make_set(int a){
        p[a] = a;
    }
};


class Solution {
public:
    vector<int> detectCycle(vector<vector<int>>& edges,vector<int>&e)
    {
        int n = edges.size();
        DSU *dsu = new DSU(n+1);
        
        for(int i=0;i<n;i++)
        {
            if(edges[i]==e)
                continue;
            
            int a = edges[i][0],b = edges[i][1];
            if(dsu->find(a)==dsu->find(b))
                return edges[i];
            
            dsu->union_set(a,b);
        }
        return {0,0};
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges)
    {
        int n = edges.size();
        vector<int>indegree(n+1,0);
        bool indegtwo = false;
        unordered_map<int,int>m;
        
        vector<int>ans1,ans2;
        vector<int>f={0,0};
        
        for(auto x:edges)
        {
            indegree[x[1]]++;
            if(indegree[x[1]]==2)
            {
                indegtwo=true;
                ans1 = {m[x[1]],x[1]};
                ans2 = x;
            }
            
            m[x[1]] = x[0];
        }
        
        if(!indegtwo)
            return detectCycle(edges,f);
        
        else if(detectCycle(edges,ans2)==f)
            return ans2;
        
        else
            return ans1;
    }
};