class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
       int n = speed.size();
       vector<pair<int,int>> Pos_Speed(n);
       vector<double> time(n);

        for(int i=0;i<n;i++)
            Pos_Speed[i] = {position[i], speed[i]};
        
        sort(Pos_Speed.begin(), Pos_Speed.end());
        
        for(int i=0;i<n;i++)
            time[i] = (1.0)*(target-Pos_Speed[i].first)/Pos_Speed[i].second;
        
        int ans=1;
        double maxTime=time[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
            if(time[i]>maxTime)      //Not a fleet
            {
                ans++;
                maxTime = time[i];
            }
            else                     //A fleet
                maxTime = max(maxTime, time[i]);    
        }
        
    return ans;
        
    }
};