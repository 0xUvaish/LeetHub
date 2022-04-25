class TimeMap {
public:
    
  unordered_map<string, map<int, string>> timeDS;
    
    TimeMap() 
    {
        timeDS.clear();
    }
    
  void set(string key, string value, int timestamp) 
  {
    timeDS[key][timestamp] = value;     
  }
    
  string get(string key, int timestamp) {
    
     if(!timeDS.count(key))
        return "";
      
    auto it = timeDS[key].upper_bound(timestamp);
      
    return (it == timeDS[key].begin()) ? "" : (--it)->second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */