class Solution {
public:
    //Also Check M2 of LC1326
    //Exacly Same to Method 3 of LC 1326 Minimum No. of Taps to Open A Water Garden
    //Inner loop is of 'for' here.....1326 has 'while' loop
    
    int videoStitching(vector<vector<int>>& clips, int time) 
    {
              sort(clips.begin(), clips.end());
              int n = clips.size();
              
              int start_time = 0, reach = 0, count = 0;
        
              int i=0;
              while(reach < time)
              {
                while(i<n && start_time >= clips[i][0]) 
                {
                    reach = max(reach, clips[i][1]);
                    i++;
                 }
                  
                  if(start_time == reach) //Start can't exceed reach
                      return -1;
                  
                  count++;
                  start_time = reach;
              }
        
         return count;         
    }
};