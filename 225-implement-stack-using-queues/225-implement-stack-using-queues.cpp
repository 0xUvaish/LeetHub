//Method 1: 2 Queues Push Efficient

// class MyStack 
// {
//     queue<int> q1;
//     queue<int> q2;
// public:
//     MyStack() 
//     {
        
//     }
    
//     void push(int x) 
//     {
//         q1.push(x);
//     }
    
//     int pop()
//     {
//         while(q1.size() != 1) 
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
        
//         int x = q1.front(); q1.pop();
//         swap(q1, q2);
//         return x;
//     }
    
//     int top() 
//     {
//         while(q1.size() != 1) 
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
        
//         int x = q1.front();
//         q1.pop();
        
//         q2.push(x);
//         swap(q1, q2);
//         return x;
//     }
    
//     bool empty() 
//     {
//         return q1.empty() && q2.empty();
//     }
// };


class MyStack 
{
    queue<int> q;
public:
    MyStack() 
    {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
    }
    
    void push(int x) 
    {
        int n = q.size();
        q.push(x);
        
        for(int i=0; i<n; i++) 
        {
            q.push(q.front()); 
            q.pop();
        }
    }
    
    int pop() 
    {
        int x = q.front(); 
        q.pop();
        
        return x;
    }
    
    int top() 
    {
        return q.front();
    }
    
    bool empty() 
    {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */