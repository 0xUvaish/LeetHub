class Solution {
public:
	int largestInteger(int num) {
		priority_queue<int> even;
		priority_queue<int> odd;
    
    int temp = num;
    while( temp )
    {
        int rem = temp % 10;
        if( rem % 2 == 0 )
            even.push(rem);
        else
            odd.push(rem);
        temp = temp / 10;
    }
    
    string s = to_string(num);
    int val = 0;
    for(int i = 0; i<s.size(); ++i)
    {
        if( (int)s[i] % 2 == 0 )
        {
            int temp = even.top();
            even.pop();
            val = val * 10 + temp;
        }
        else
        {
            int temp = odd.top();
            odd.pop();
            val = val * 10 + temp;
        }
    }
    
    return val;
	}
};