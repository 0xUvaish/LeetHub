class Solution {
public:
    
    //Sol 1: Brite Force (TLE)
//     bool isSubsequence(string s, string word)
//     {
//         int i=0,j=0;
//         int n = s.size(), m = word.size();
//         while(i<n && j<m)
//         {
//             if(s[i]==word[j])
//                 j++;
            
//             i++;
            
//             if(j==m)
//                 break;
//         }
        
//         return j==m;
//     }
    
//     int numMatchingSubseq(string s, vector<string>& words) {
//         int cnt=0;
//         for(auto word: words)
//             if(isSubsequence(s, word))
//                 cnt++;
        
//     return cnt;
//     }
    
    //Sol 2: Using Map & Binary Search
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        unordered_map<int, vector<int>> loc;  //Index of each character in "string s"
        
        for(int i = 0; i < s.length(); i++)
            loc[s[i] - 'a'].push_back(i);
        
        long long  int cnt = 0;
        
        for(int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            int prev_idx = -1;
            int j = 0;
            
            for(j = 0; j < word.length(); j++) 
            {
                auto &v = loc[word[j] - 'a'];
                auto it = upper_bound(v.begin(), v.end(), prev_idx);//prev_idx to maintain order for subsequence
                
                if(it == v.end())
                    break;
                else 
                    prev_idx = *it;
            }
            
            if(j == word.length())
                cnt++;
            
        }
        
        return cnt;
    }
};