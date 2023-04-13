class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int pointerPopped = 0;
		stack<int> st;
        
		for(int i = 0; i < pushed.size(); i++) 
        {
			st.push(pushed[i]);
			while (!st.empty() && pointerPopped < popped.size() && st.top() == popped[pointerPopped])
            {
				st.pop();
				pointerPopped++;
			}
		}
        
		if (pointerPopped >= popped.size() && st.empty())
			return true;
        
		return false;
	}
};