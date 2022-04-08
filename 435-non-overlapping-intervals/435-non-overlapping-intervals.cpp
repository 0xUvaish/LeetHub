class Solution {
public:
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int ans=0;
        sort(intervals.begin(),intervals.end()); 
        
        auto prev=intervals[0];
        for(int i=1;i<intervals.size();i++)
        {
            if(prev[1]>intervals[i][0])                       //overlapping
            {
                ans++;
                prev[1] = min(prev[1], intervals[i][1]);      //keep with min end time or Removed larger end time
            }
            else
                prev=intervals[i];
        }
        
        return ans;
    }
};