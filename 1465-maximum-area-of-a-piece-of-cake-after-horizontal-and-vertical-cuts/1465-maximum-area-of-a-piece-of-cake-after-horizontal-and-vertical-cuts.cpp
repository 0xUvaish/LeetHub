class Solution {
public:
    int maxArea(int ht, int w, vector<int>& h, vector<int>& v) {
        int mod=1e9+7;
        h.push_back(ht);
        v.push_back(w);
        
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        
        int max_v=(v[0]-0)%mod;
        int max_h=(h[0]-0)%mod;
        
        for(int i=1;i<h.size();i++) 
            max_h=max(max_h%mod,(h[i]%mod-h[i-1]%mod)%mod);
        
        for(int i=1;i<v.size();i++) 
            max_v=max(max_v%mod,(v[i]%mod-v[i-1]%mod)%mod);
        
        long long t=max_h;
        long long r=max_v;
        
        return (t*r)%mod;
    }
};