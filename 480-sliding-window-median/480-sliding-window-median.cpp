class Solution {
public:
// https://leetcode.com/problems/sliding-window-median/discuss/1364984/C%2B%2B-SIMPLE-code-using-Multiset-Shorter-Replicable-for-Interviews
    
    void insert(multiset<double,greater<double>> &maxx, multiset<double> &minn, int num)
    {
            if(maxx.empty() || num<*maxx.begin())
                maxx.insert(num);
            else
                minn.insert(num);
    }
    
    void balance(multiset<double,greater<double>> &maxx, multiset<double> &minn)
    {
            if(maxx.size() < minn.size())
            {
                maxx.insert(*minn.begin());
                minn.erase(minn.begin());
            }
            else if(minn.size() + 1 < maxx.size())
            {
                minn.insert(*maxx.begin());
                maxx.erase(maxx.begin());
            }
    }
    
    void add_median(multiset<double,greater<double>> &maxx, multiset<double> &minn, vector<double> &median)
    {
        if(maxx.size() == minn.size())
            median.push_back((*maxx.begin() + *minn.begin())/2.0);
        else if(maxx.size() > minn.size())
            median.push_back(*maxx.begin());
        
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        multiset<double> minn;
        multiset<double,greater<double>> maxx;
        
        vector<double> median;
        
        for(int i = 0; i<k; i++)
        {
            insert(maxx,minn,nums[i]);
            balance(maxx,minn);
        }
        
        add_median(maxx,minn,median);

        for(int i = k; i<nums.size(); i++)
        {                                        //Remove outgoing from left
            auto lcheck = maxx.find(nums[i-k]);
            auto rcheck = minn.find(nums[i-k]);
            
            if(lcheck != maxx.end())
                maxx.erase(lcheck);
            else
                minn.erase(rcheck);
        
            balance(maxx,minn);
            insert(maxx,minn,nums[i]);         //Insert incoming from right
            balance(maxx,minn);
            
            add_median(maxx,minn,median);      
        }
    
        return median;
    }
};