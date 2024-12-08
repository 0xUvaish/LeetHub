class MinStack {
    
// private:
//     stack<pair<int, int>> s;
//     int curr_min = INT_MAX;
    
// public:
//     MinStack() {}
    
//     void push(int val) 
//     {
//         if (val < curr_min)
//             curr_min = val;

//           s.push({val, curr_min});
//     }
    
//     void pop() {
//         s.pop();
//         curr_min = s.empty() ? INT_MAX : s.top().second;
//     }
    
//     int top() {
//         return s.top().first;
//     }
    
//     int getMin() {
//         return curr_min;
//     }
    
public:
    stack<long> st;
    long minval;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            minval=val;
            st.push(val);
            return;
        }
        else{
            if(val>=minval)
                st.push(val);
            else{
                st.push(2ll*val-minval);
                minval=val;
            }
        }
    }
    
    void pop() {
        if(st.top()>=minval)
            st.pop();
        else{
            minval=2ll*minval-st.top();             //At this point during push val became minval so same equation is written
            st.pop();
        }
    }
    
    int top() {
        if(st.top()>=minval)
            return st.top();
        else{
            return minval;
        }
    }
    
    int getMin() {
        if(st.empty())
            return -1;
        return minval;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */