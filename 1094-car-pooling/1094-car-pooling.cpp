class Solution {
public:
    bool  static compare(vector<int>A,vector<int>B)
    {
        return A[1]<B[1];
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) 
    {
        sort(trips.begin(),trips.end(),compare);
        int curr_pass=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        for(int i=0;i<trips.size();i++)
        {
            while(!pq.empty()&&pq.top().first<=trips[i][1])
            {
                curr_pass-=trips[pq.top().second][0];
                pq.pop();
            }
            
            curr_pass+=trips[i][0];
            
            if(curr_pass>capacity)
                return false;
            
            pq.push({trips[i][2],i});
        }
        
        return true;
    }
};