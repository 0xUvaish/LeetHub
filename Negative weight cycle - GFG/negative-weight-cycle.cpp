// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	   int source = 0;
       vector<int> distance(n, 100000000);
       distance[source] = 0;
       
       for(int i = 0; i < n - 1; i++)
           for(auto &edge:edges)
               if(distance[edge[0]] + edge[2] < distance[edge[1]])
                   distance[edge[1]] = distance[edge[0]] + edge[2];
                   
                   
       for(auto &edge:edges)
           if (distance[edge[0]] + edge[2] < distance[edge[1]])
               return 1;
               
       return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends