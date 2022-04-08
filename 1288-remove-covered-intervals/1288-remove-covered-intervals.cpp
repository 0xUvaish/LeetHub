class Solution {
public:
    bool static comp(vector<int> &A, vector<int> &B)
    {
        if(A[0]!=B[0])
            return A[0]<B[0];
        else
            return A[1]>B[1];
    }
    
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(), comp);        
        int n = intervals.size();
        int endtime = intervals[0][1];
        int res=1;
        
        for(auto it: intervals)
        {
            if(endtime>=it[1])     //completely submerged
                continue;
            else
            {
                res++;
                endtime = it[1];
            }
        
        }
        
        return res;
    }
};