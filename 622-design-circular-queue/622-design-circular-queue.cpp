class MyCircularQueue 
{
    list<int> dLL;
    int size, maxCap;
public:
    
    /*
    Constructor
    isEmpty
    isFull
    Front
    Rear
    enQueue
    deQueue
    */
    
    MyCircularQueue(int k)
    {
        size = 0;
        maxCap = k;
    }
    
    bool isEmpty() 
    {
        return size == 0;
    }
    
    bool isFull()
    {
        return size == maxCap;
    }
    
    int Front() 
    {
        return !isEmpty() ? dLL.front() : -1;
    }
    
    int Rear() 
    {
        return !isEmpty() ? dLL.back() : -1;
    }
    
    bool enQueue(int value) 
    {
        if(isFull() == false) 
        {
            dLL.push_back(value);
            size++;
            return true;
        }
        return false;
    }
    
    bool deQueue()
    {
        if(isEmpty() == false) 
        {
            dLL.pop_front();
            size--;
            return true;
        }
        return false;
    }
    
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */