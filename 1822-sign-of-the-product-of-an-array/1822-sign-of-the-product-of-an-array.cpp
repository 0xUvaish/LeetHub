class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg=0;
        for(auto x: nums)
        {
            if(x==0)
                return 0;
            
            if(x<0)
                neg++;
        }
        
        if(neg%2==0)
            return 1;
        else 
            return -1;
    }
};