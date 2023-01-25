class Solution {
public:
    void dfs(vector<int>& edges,int node,vector<int>& arr)
    {
        int v=edges[node];
        if(v!=-1 and arr[v]==-1)
        {
            arr[v]=1+arr[node];
            dfs(edges,v,arr);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>first(n,-1);
        vector<int>second(n,-1);

        first[node1]=0;
        second[node2]=0;

        dfs(edges,node1,first);
        dfs(edges,node2,second);
        
        int mini=1e6;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(first[i]==-1 or second[i]==-1)
                continue;
            if(mini>max(first[i],second[i]))
            {
                mini=max(first[i],second[i]);
                ans=i;
            }
        }
        return ans;
    }
};