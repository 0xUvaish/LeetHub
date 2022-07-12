class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        int ans = 0;
        bool flag = false;
        unordered_map<string, int> m;

        for(auto i : words)
            m[i]++;

        for(auto i : m)
        {
            string tmp = i.first;
            if(tmp[0] == tmp[1])
            {
                if(!flag && i.second % 2==1)
                    flag = true;

                int t = i.second / 2;
                ans += t * 4;
            }
            else
            {
                string tmp2 = tmp;
                reverse(tmp2.begin(), tmp2.end());
                if(m.find(tmp2) != m.end())
                    ans += min(m[tmp], m[tmp2]) * 4, m.erase(tmp2);   
            }
        }

        return ans + (flag ? 2 : 0);
    }
};