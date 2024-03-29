class FreqStack {
public:
    map<int,int> freqMap;
    map<int,stack<int>> setMap;
    
    int maxfreq;
    
    FreqStack() 
    {
       maxfreq=0; 
    }
    
    void push(int val) 
    {

        freqMap[val]++;
        int freq = freqMap[val];
        
        setMap[freq].push(val);
        
        maxfreq = max(freq, maxfreq);
    }
    
    

    int pop() 
    {

        int top = setMap[maxfreq].top();
        setMap[maxfreq].pop();
        
        freqMap[top]--;

        if(setMap[maxfreq].size() == 0)
            maxfreq--;
        
        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */