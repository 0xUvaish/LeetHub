class Solution {
public:
    bool isValid(vector<int>&weights, int days, int max)
    {
        int day = 1;
        int sum = 0;
        
        for(int i=0; i<weights.size();i++)
        {
            sum += weights[i];
            if(sum > max)
            { 
                day++;
                sum = weights[i];
            }
            
            if(day > days)
                return false;
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int start=INT_MIN, end=0;
        
        for(auto x : weights)
        {
            start = max(start, x);
            end += x;
        }
        
        int ans = -1;
        while(start <= end)
        {
            int mid = (start + end) >> 1;
            
            if(isValid(weights, days, mid))
            {   
                ans = mid;
                end = mid -1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};