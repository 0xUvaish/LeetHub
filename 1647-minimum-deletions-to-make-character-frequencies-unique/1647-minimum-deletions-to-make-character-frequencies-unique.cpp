class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26,0),v;
        
        for(auto &k: s) 
            cnt[k-'a']++;
        
        for(auto &k: cnt) 
            if(k) 
                v.push_back(k);
        
        // sort counts in v in decreasing order.
        sort(v.begin(),v.end(),[&](int x, int y) -> bool{
           return x>y; 
        });
        
        // now starting from biggest element , start decrementing till it is present before.
        int count=0;
        unordered_set<int> st;
        for(int i=0;i<v.size();i++){
            while(v[i]>0 && st.count(v[i])){
                v[i]--;
                count++;
            }
            
            st.insert(v[i]);
        }
        
        return count;
    }
};