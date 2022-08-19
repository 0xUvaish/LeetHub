class Solution {
public:
	bool isPossible(vector<int>& nums)
    {
        unordered_map<int, int> cur, tmp;
        
        for(int i : nums) 
            cur[i]++;
        
        for(int i : nums)
        {
            if(cur[i] == 0) 
                continue;
            cur[i]--;
            
            if(tmp[i - 1]-- > 0) 
                tmp[i]++;
            else if(cur[i + 1]-- > 0 && cur[i + 2]-- > 0) 
                tmp[i + 2]++;
            else 
                return false;
        }
        return true;
    }
};