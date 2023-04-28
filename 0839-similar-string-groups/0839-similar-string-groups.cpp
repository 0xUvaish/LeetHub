class Solution {
public:

    vector<int> par,rank;
    // function to update parent and return super parent of a
    int get(int a){
        if(par[a] == -1) return a;
        return par[a] = get(par[a]);
    }
    // function to unite 2 groups of a and b
    void un(int a,int b){
        int pa = get(a);
        int pb = get(b);
        if(pa != pb){
            if(rank[pa] >= rank[pb]){
                par[pb] = pa;
                rank[pa] += rank[pb];
            }else{
                par[pa] = pb;
                rank[pb] += rank[pa];
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        int ans = 0;
        par.resize(strs.size(),-1);
        rank.resize(strs.size(),1);
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                if(strs[i] == strs[j]){
                    un(i,j);
                }
                string te1 = "", te2 = "";
                for(int k=0;k<strs[i].size();k++){
                    if(strs[i][k] != strs[j][k]){
                        te1 += strs[i][k];
                        te2 += strs[j][k];
                    }
                    if(te1.length()>2) break;
                }
                if(te1.length() == 2 && (te1[0] == te2[1] && te1[1] == te2[0])){
                    un(i,j);
                }
            }
        }
        for(int i: par)
            if(i == -1) ans++;
        return ans;
    }
};