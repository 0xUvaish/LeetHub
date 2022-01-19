class Solution {
public:
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string,int> mp;
    vector<string> vs;
    int cnt=0;
    for(int i=0;i<s.length();i++)
    {
        if(i+9<=s.length()-1)
        {
            string st = s.substr(i,10);
            if(mp[st])
            {
                if(mp[st]==1)
                {
                    vs.push_back(st);
                    mp[st]++;
                }
            }
            else
            {
                mp[st]++;
            }
        }
        else
        {
            break;
        }
    }
    
    return vs;
    
}
    
};