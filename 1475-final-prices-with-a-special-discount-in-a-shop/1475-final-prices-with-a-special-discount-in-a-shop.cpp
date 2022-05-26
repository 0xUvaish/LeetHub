class Solution {
public:
vector<int> finalPrices(vector<int>& prices) {
    int size=prices.size(); int updated;
    vector<int> ans(size);
    stack<int> s;
    s.push(0);
    for(int i=size-1;i>=0;i--)
    {
        int ele=prices[i];
        while(s.top()>ele)
            s.pop();
        
        updated=prices[i]-s.top();
        ans[i]=updated;
        s.push(ele);
    }
    return ans;
 }
};