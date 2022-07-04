class Solution {
public:
vector<int> grayCode(int n) {
    
    vector<int>ans;
    int k = pow(2,n);
    
    for(int i=0;i<k;i++)
        ans.push_back(i ^ (i>>1));
    
    return ans;
    }
};