class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int currSum=0;
        int mn=INT_MAX;
        int mnIdx=0;
        for(int i=0;i<gas.size();i++)
        {
            currSum+=(gas[i]-cost[i]);
            if(mn>currSum)
            {
                mn=currSum;
                mnIdx=i;
            }
        }
        if(currSum>=0)
            return (mnIdx+1)%gas.size();
        
        return -1;
    }
};