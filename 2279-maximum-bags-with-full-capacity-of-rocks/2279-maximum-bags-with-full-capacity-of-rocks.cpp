class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
       int n = capacity.size();
       vector<int> remain(n);
        
       for(int i=0;i<n;i++)
           remain[i]=capacity[i]-rocks[i];
        
       sort(remain.begin(),remain.end());
        
       int rest=additionalRocks;
       int count=0;
        
      for(int i=0;i<n;i++)
      {
        if(remain[i]!=0 && remain[i]<=rest)
        {
         rest -= remain[i];
         remain[i]=0;
        }
          
        if(remain[i]==0)
            count++;
      }
        
    return count;
    }
};