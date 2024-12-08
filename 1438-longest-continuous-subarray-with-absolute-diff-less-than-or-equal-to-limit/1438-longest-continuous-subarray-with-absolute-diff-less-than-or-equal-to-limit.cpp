class Solution {
public:
    int longestSubarray(vector<int>& n, int l)
    {
        deque<int> maxx, minn;
        
        int i=0, j=0, ans = 1;
        
        while(j<n.size())
        {
            int curr = n[j];    
            
            while(!maxx.empty() && n[maxx.back()]<=curr)     //2nd step of SW Maximum
                maxx.pop_back(); 
            
            maxx.push_back(j);                               //3rd step of SW Maximum
            
            while(!minn.empty() && n[minn.back()]>=curr)     //2nd step of SW Minimum
                minn.pop_back(); 
            
            minn.push_back(j);                               ////3rd step of SW Minimum
            
            
            
            while(abs(n[maxx.front()]-n[minn.front()]) > l)
            {
                if(maxx.front()==i)                         
                    maxx.pop_front();
                
                if(minn.front()==i)
                    minn.pop_front(); 
                
                i++;
            }      
            
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};