class Solution {
public:
int maximumLength(string s) {
    int count = 0, last = s[0], ans = 0;
    unordered_map<char, vector<int>> ump;   // this store the cont. occurance counts against each character
    for(auto c: s){                         // compute all the cont. char count and add it to the corresponding char in the map
        if(c == last) count++;
        else{
            ump[last].push_back(count);
            count = 1;  last = c;
        }
    }
    ump[last].push_back(count);
    
    for(auto [k, v]: ump){                 // For each char evaluate the max 3 occuarance count and check for possible max triplate count        
        int l1 = 0, l2 = 0, l3 = 0;
        for(auto e: v){ 
            if(l1 < e) { l3 = l2; l2 = l1; l1 = e; }
            else if(l2 < e) { l3 = l2; l2 = e; }
            else if(l3 < e) { l3 = e; }
        }
        if(l1 == l2 && l1 > l3) l2--;      // This is to handle the case when the largest 3 occurances are 2, 2, 1
        if(l1 + l2 + l3 >= 3) ans = max({ans, l1 - 2, l2 });  //max triplet can be either largest - 2 or the second largest
    }
    return ans != 0?ans: -1;               // if ans is zero return -1 otherwise return ans.
}
};