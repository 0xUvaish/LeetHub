class Solution {
public:
    bool isPossible(vector<int>& target) {
        if(target.size()==1)
           return (target[0]==1);
        
        priority_queue<int> pq;
        long long tsum = 0;
        for(auto it : target)
        {
            tsum += it;
            pq.push(it);
        }
        
        long long maxEle;
        while(!pq.empty() && pq.top()!=1)
        {
            maxEle = pq.top();
            pq.pop();
            long long rsum = tsum-maxEle;
            long long element;
            
            //If-else is optimisation from TLE
            if(maxEle<2*rsum)
                element = maxEle-rsum;
            else
            {
                long long multi = 1;
                if(maxEle%2==0)
                    multi = (maxEle/rsum)-1;
                else
                    multi = maxEle/rsum;
                
                element = maxEle-multi*rsum;
            }
            
            if(element<=0) 
                return false;
            
            pq.push(element);
            tsum = rsum+element;
        }
        return true;
    }
};