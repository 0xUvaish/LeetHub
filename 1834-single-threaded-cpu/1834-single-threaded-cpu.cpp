class Solution {
public:
    
    //Shortest Job First Process Scheduling
    vector<int> getOrder(vector<vector<int>>& tasks) 
    {
       //No comparator needed in Priority Queue in case of Pair<int,int>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        long n = tasks.size();
        
        for(int i=0; i<n; i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(), tasks.end());
        vector<int> order;
        
        long time = 0, i=0;
        
        while(i<n || !pq.empty())
        {
            //CPU is Idle
            if(pq.empty())
                time = max(time, (long)tasks[i][0]);
            
            //Insert all task which arrived till the 'time'
            while(i<n && tasks[i][0]<=time)
            {
                pq.push(make_pair(tasks[i][1], tasks[i][2]));
                i++;
            }
            
            //Processing one task at a time
            auto Job = pq.top();
            pq.pop();
            
            order.push_back(Job.second);
            
            time += Job.first;  //Update time by adding current job's burst
            
        }
        return order;
        
    }
};