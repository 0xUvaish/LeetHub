class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,bool>m;
        int ans = 0;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]=true;
            }else{
                ans++;
                m.clear();
                m[s[i]]=true;
            }
        }
        return ans+1;
        
    }
};