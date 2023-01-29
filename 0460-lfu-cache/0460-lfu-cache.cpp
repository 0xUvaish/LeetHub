class LFUCache {
public:
    struct Info{
        int value;
        int counter = 1;
    };

    int size;
    unordered_map<int, Info> main_mp;   // keep cache members
    map<int, deque<int>> cnt_mp;    // keep members' last using time, from long to short

    // ------------------- For Debugging ------------------- 
    void printMp(){
        cout << "printmp" << endl;
        for(auto &it : main_mp){
            cout << it.first << ": {" << it.second.value << "," << it.second.counter << "} ";
        }
        cout << endl;
    }

    void printCounters(){
        cout << "printCounters" << endl;
        for(auto &it : cnt_mp){
            cout << it.first << ": ";
            for (auto n: it.second)  cout << n << " ";
            cout << endl;
        }
    }
    // ------------------- For Debugging ------------------- 

    LFUCache(int capacity) {
        size = capacity;
        main_mp.clear();
        cnt_mp.clear();
    }

    void updateCounter(int key, int org_cnt){
        cnt_mp[org_cnt + 1].push_back(key); 

        deque<int>::iterator it = find(cnt_mp[org_cnt].begin(), cnt_mp[org_cnt].end(), key);
        cnt_mp[org_cnt].erase(it); 
        
        if(cnt_mp[org_cnt].size()==0) cnt_mp.erase(org_cnt);
    }

    int popOutLFU(){
        int tmp = cnt_mp.begin()->first;
        int removeId = cnt_mp[tmp].front();
        cnt_mp[tmp].pop_front();
        if(cnt_mp[tmp].size()==0) cnt_mp.erase(tmp);
        return removeId;
    }

    int get(int key) {
        if(main_mp.find(key) == main_mp.end()) return -1;
        else{
            updateCounter(key,  main_mp[key].counter);
            main_mp[key].counter++;
            return main_mp[key].value;
        }         
    }
    
    void put(int key, int value) {
        if(main_mp.find(key) != main_mp.end()){ // already exist
            main_mp[key].value = value;
            updateCounter(key,  main_mp[key].counter);            
            main_mp[key].counter ++ ;
        }
        else{
            if(size == 0) return;
            if(size == main_mp.size()){  // remove LFU
                int tmp = popOutLFU();
                main_mp.erase(tmp);
            }
            main_mp[key] = Info{value, 1};
            cnt_mp[1].push_back(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */