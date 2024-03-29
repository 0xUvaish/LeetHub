class Solution {
public:
 int maxPoints(vector<vector<int>>& points) {
        int N=points.size() , ans=1;
		
        for(int i=0;i<N;i++)
        {
		
            unordered_map<float,int>slopes;
            for(int j=i+1;j<N;j++)
            {
                float dx= points[j][0]-points[i][0];
                
                if(dx==0)
                    slopes[INT_MAX]++;        //infinite dy/dx
                else
                {
                    float dy=points[j][1]-points[i][1];
                    slopes[dy/dx]++;
                }
            }
			
            for(auto sl:slopes)
                ans=max(ans,sl.second+1);
        }
		
        return ans;
    }
};