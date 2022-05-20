class Solution {
public:
vector<int> grayCode(int n) {
    
    vector<int>ans;
    for(int i=0;i<=(pow(2,n)-1);i++)
    {
        ans.push_back(i ^ (i>>1));
    }
    
    return ans;
}
};