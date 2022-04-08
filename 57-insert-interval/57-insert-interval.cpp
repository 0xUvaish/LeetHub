class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i=0;
        
        vector<vector<int >> ans;
        
        //No overlapping before newInterval will be just inserted into resultant ans
        while(i<n && intervals[i][1]<newInterval[0])
        {
           ans.push_back(intervals[i]); 
           i++;  
        }
        
        //In case there is overlapping, grab all overlapping and merge into ine
        while(i<n && newInterval[1]>=intervals[i][0])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        
        //Push this merged interval
        ans.push_back(newInterval);
        
        //Remaining non-overlapping intervals needs to be pushed
        
        while(i<n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        
return ans;
        
        
    }
};