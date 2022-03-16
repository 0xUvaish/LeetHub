class Solution {
public:
        
   int parent(int a,vector<int>& un)
    {
        while(un[a]!=-1)
            a=un[a];
       
       return a;  
    }
    
    int makeConnected(int n, vector<vector<int>>& connections)
    {
       int size=connections.size(),ans=0;
        if(size<n-1)
            return -1;
        
        vector<int>un(n,-1);

        for(int i=0;i<size;i++)
        {
           auto a = parent(connections[i][0], un);
           auto b = parent(connections[i][1], un);
            
            if(a!=b)
                un[b]=a;
        }
        for(auto & i:un)
            if(i==-1)  //nodes which are non reachable
                ans++;
        
        return ans-1;   //because un[0]=-1 for first node
    }

};