class Solution {
public:
    int parent[26], rank[26]={0};
    
    void union_set(int a, int b)
    {
        int pA = find(a);
        int pB = find(b);
        if(pA==pB)
            return;
        
        if(rank[pA]>rank[pB])
        {
            parent[pB] = pA;
            rank[pA]++;
        }
        else
        {
            parent[pA] = pB;
            rank[pB]++;
        }  
    }
    
    int find(int a)
    {
        if(parent[a] == a) 
            return a;
        
        return parent[a] = find(parent[a]);
    }
    
    
    bool equationsPossible(vector<string>& eq) 
    {
        int n=eq.size();
        for(int i=0;i<26;i++)   
            parent[i] = i;
        
        for(int i=0;i<n;i++)
            if(eq[i][1]=='=') 
                union_set(eq[i][0]-'a',eq[i][3]-'a');
        
        for(int i=0;i<n;i++)      
            if(eq[i][1]=='!' && find(eq[i][0]-'a') == find(eq[i][3]-'a'))
                return false;
        
        return true;
    }
};