class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        set<int> stt;
        
        for(int &i:nums)
        {
            if(i%2) i*=2;
            
            stt.insert(i);
        }
        
        //*rbegin() itrator contain max number
        // *begin() iterator contain min number
        
        // finding min dev
        int mindev= *stt.rbegin() - *stt.begin();
        
        while(*stt.rbegin()%2==0)
        {
            stt.insert(*stt.rbegin()/2);
            stt.erase(*stt.rbegin());
            mindev = min(mindev, *stt.rbegin()-*stt.begin());
        }
        
        return mindev;
    }
};