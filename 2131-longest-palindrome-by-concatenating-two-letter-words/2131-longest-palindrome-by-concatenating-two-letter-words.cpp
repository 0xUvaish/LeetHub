class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        int ans = 0;
        bool odd_twins = false;
        unordered_map<string, int> m;

        for(auto i : words)
            m[i]++;

        for(auto i : m)
        {
            string tmp = i.first;
            if(tmp[0] == tmp[1])
            {
                int t = i.second / 2;   //Twins with even freq to be added(ll,ll or cc,cc,cc,cc or pp,pp from pp,pp,pp, i.e., extracting even frequencies)
                ans += t * 4;
                
                
                if(!odd_twins && i.second % 2==1)   //To handle one odd twin
                    odd_twins = true;
            }
            else
            {
                string tmp2 = tmp;
                reverse(tmp2.begin(), tmp2.end());
                if(m.find(tmp2) != m.end())
                    ans += min(m[tmp], m[tmp2]) * 4, m.erase(tmp2);   
            }
        }

        return ans + (odd_twins ? 2 : 0);
    }
};