class MyHashMap {
    
    /* Order of Methods ->
    Contructor
    Hash
    Search list iterator
    Contains
    Remove Mapping
    Get Key-Value
    Put Key-Value (uses remove)
    */
    
public:
    vector<list<pair<int,int>>> m;
    int siz;
    
    MyHashMap() 
    {
        siz=1e6+1;
        m.resize(siz);
    }
    
    int hash(int key)
    {
        return key%siz;
    }
    
    list<pair<int,int>> :: iterator search(int key)
    {
        int i = hash(key);
        
        auto it = m[i].begin();
        while(it!=m[i].end())
        {
            if(it->first == key)
                return it;
        }
        
        return it;
    }
    
    bool contains(int key) 
    {   
        int i = hash(key);
        
        if(search(key) != m[i].end())
            return true;
        else
            return false;
    }
    
    void remove(int key) 
    {
        if(!contains(key))
             return;
        
        int i = hash(key);
        m[i].erase(search(key));   
    }
    
    int get(int key) 
    {
        if(!contains(key))
             return -1;
        
        int i = hash(key);
        return (search(key)->second);  
    }
    
    void put(int key, int value) 
    {
        remove(key);
        
        int i = hash(key);
        m[i].push_back({key,value});  
    }
    
    
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */