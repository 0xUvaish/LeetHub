class Solution {
public:
    void combo(string &digits,int index,string res,vector<string> &ans,vector<char> mapping[],int size)
    {
        if(index==size)
        {
            ans.push_back(res);
            return;
        }
        int digit=digits[index]-'0';
        int len=mapping[digit].size();
        for(int i=0;i<len;i++)
        {
            combo(digits,index+1,res+mapping[digit][i],ans,mapping,size);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<char> mapping[]={{},{},{'a','b','c'},{ 'd', 'e', 'f' },
        { 'g', 'h', 'i' },
        { 'j', 'k', 'l' },
        { 'm', 'n', 'o' },
        { 'p', 'q', 'r', 's'},
        { 't', 'u', 'v' },
        { 'w', 'x', 'y', 'z'}};
        string res;
        vector<string> ans;
        int size=digits.size();
        if(size==0)
            return {};
        combo(digits,0,res,ans,mapping,size);
        return ans;
    }
};