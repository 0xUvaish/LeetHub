class Solution {
public:
int minCharacters(string str1, string str2)
{
    int l1 = (int) str1.length(), l2 = (int) str2.length();
    vector<int> freq1(26, 0), freq2(26, 0);
    int ans = l1 + l2;
    
    for(auto x: str1)
        freq1[x-'a']++;
    
    for(auto x: str2)
        freq2[x-'a']++;
    
    for(int i = 0; i < 26; i++)
    {
        ans = min(ans, l1 - freq1[i] + l2 - freq2[i]);
        
        if(i > 0)
        {
            freq1[i] += freq1[i-1];
            freq2[i] += freq2[i-1];
        }
        if(i < 25)
        {
            ans = min(ans, freq1[i] + l2 - freq2[i]);
            ans = min(ans, freq2[i] + l1 - freq1[i]);
        }
    }
    return ans;
}
};