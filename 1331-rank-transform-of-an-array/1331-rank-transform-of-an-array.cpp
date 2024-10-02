class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> m;
        vector<int> ans;
        int cnt=1;
        for(auto i : arr)
        {
            m[i]++;
        }
        for(auto i : m)
        {
            m[i.first] = cnt;
            cnt++;
        }
        for(int i=0;i<arr.size();i++)
        {
            ans.push_back(m[arr[i]]);
        }
        return ans;
    }
};