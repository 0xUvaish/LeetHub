class MyHashSet {
    
    /* Order of Methods ->
    Contructor
    Hash
    Search list iterator
    Contains
    Add Key
    Remove Key
    */
    
public:
    vector<list<int>> m;
    int siz;
    
    MyHashSet() 
    {
        siz=1e6+1;
        m.resize(siz);
    }
    
    int hash(int key)
    {
        return key%siz;
    }
    
    list<int> :: iterator search(int key)
    {
        int i = hash(key);
        return find(m[i].begin(), m[i].end(), key);
    }

    bool contains(int key) 
    {   
        int i = hash(key);
        
        if(search(key) != m[i].end())
            return true;
        else
            return false;
    }
    
    void add(int key) 
    {
         if(contains(key))
             return;
        
        int i = hash(key);
        m[i].push_back(key);
    }
    
    void remove(int key) 
    {
         if(!contains(key))
             return;
        
        int i = hash(key);
        m[i].erase(search(key));        
    }
    
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */