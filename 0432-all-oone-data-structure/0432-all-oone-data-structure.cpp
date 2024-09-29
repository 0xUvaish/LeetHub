class AllOne {
public:
    
    map<string, int> mp;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> mini;
    priority_queue<pair<int, string>> maxi;
    
    
    AllOne(){
        // WASTE
    }
    
    void inc(string key) {
        mp[key]++;
        mini.push({mp[key], key});
        maxi.push({mp[key], key});
    }
    
    void dec(string key) {
        mp[key]--;
        mini.push({mp[key], key});
        maxi.push({mp[key], key});
    }
    
    string getMaxKey() {
        while(maxi.size()){
            if(maxi.top().first == mp[maxi.top().second] && mp[maxi.top().second]){
                return maxi.top().second;
                break;
            }else{
                maxi.pop();
            }
        }return "";
    }
    
    string getMinKey() {
        while(mini.size()){
            if(mini.top().first == mp[mini.top().second] && mp[mini.top().second]){
                return mini.top().second;
                break;
            }else{
                mini.pop();
            }
        }return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */