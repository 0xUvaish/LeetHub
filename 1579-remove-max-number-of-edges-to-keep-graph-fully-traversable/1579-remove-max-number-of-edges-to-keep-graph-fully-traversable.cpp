int p1[100005];
int Find1(int x){
    if(p1[x] == x) return x;
    return p1[x] = Find1(p1[x]);
}
void Union1(int a, int b){
    p1[Find1(b)] = Find1(a);
}
int p2[100005];
int Find2(int x){
    if(p2[x] == x) return x;
    return p2[x] = Find2(p2[x]);
}
void Union2(int a, int b){
    p2[Find2(b)] = Find2(a);
}
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        for(int i = 1; i <= n; i++){
            p1[i] = p2[i] = i;
        }
        int com1 = 0, com2 = 0;
        int edge = 0;
        for(auto &it: edges){
            if(it[0] == 3){
                bool ok = false;
                if(Find1(it[1]) != Find1(it[2])){
                    com1++;
                    Union1(it[1], it[2]);
                    ok = true;
                }
                if(Find2(it[1]) != Find2(it[2])){
                    com2++;
                    Union2(it[1], it[2]);
                    ok = true;
                }
                if(ok) edge++;
            }
        }
        for(auto &it: edges){
            if(it[0] == 1){
                if(Find1(it[1]) != Find1(it[2])){
                    com1++;
                    Union1(it[1], it[2]);
                    edge++;
                }
            }
            else if(it[0] == 2){
                if(Find2(it[1]) != Find2(it[2])){
                    com2++;
                    Union2(it[1], it[2]);
                    edge++;
                }
            }
        }
        if(com1 == n-1 && com2 == n-1){
            return edges.size()-edge;
        }
        return -1;
    }
};