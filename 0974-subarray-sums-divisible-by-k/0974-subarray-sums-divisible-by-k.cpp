class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map <int, int> m;
        m[0]=1;
        int prefix_sum = 0, ans = 0;
        for(int i=0; i<n; i++)
        {
            prefix_sum += nums[i];
            int rem = (prefix_sum%k + k)%k;  // when rem<0 add k
            
            if(m.find(rem-0)!=m.end())
                ans += m[rem]; 
            
            m[rem]++;
        }
        
        return ans;
    }
};