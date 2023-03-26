class Solution {
public:
    int ans=INT_MIN;
    int len=0;
    bool flag=false;
    int node=-1;

    void DFSTraversal(int index,unordered_map<int,vector<int>> &adjList,vector<bool> &visited,
    vector<bool> &dfsArray){
        visited[index]=true;
        dfsArray[index]=true;
        for(auto neighbour:adjList[index]){
            if(!visited[neighbour]){
                DFSTraversal(neighbour,adjList,visited,dfsArray);
            }
            else if(dfsArray[neighbour]==true){
                node=neighbour;
                flag=true;
            }
        }
        if(flag && index!=node){
            len++;
        }
        else if(flag && index==node){
            len++;
            ans=max(ans,len);
            flag=false;
        }
        dfsArray[index]=false;
        return;
    }

    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>> adjList;
        for(int i=0;i<n;i++){
            if(edges[i]==-1){
                continue;
            }
            adjList[i].push_back(edges[i]);
        }
        vector<bool> visited(n,false);
        vector<bool> dfsArray(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                DFSTraversal(i,adjList,visited,dfsArray);
                node=-1;
                len=0;
            }
        }

        return ans==INT_MIN?-1:ans;
    }
};