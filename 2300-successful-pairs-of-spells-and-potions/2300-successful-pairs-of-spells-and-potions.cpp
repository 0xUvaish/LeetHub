class Solution {
public:
    int help(int spell, vector<int>& potions, long long success)
    {
        int m = potions.size();
        int high = m-1;
        int low=0;
        int ans=0;
        while(low<=high)
        {
            int mid = (low+high)/2;
            long long temp = 1ll*(spell)*1ll*(potions[mid]);
            if(temp>=success)
            {
                ans = m-mid;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        
    return ans;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());
        
        for(int i=0;i<n;i++)
        {
            int spell = spells[i];
            int answer = help(spell, potions, success);
            ans[i] = answer;
        }
        
    return ans;
    }
};