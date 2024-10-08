class Solution {
public:
    //Use ladders for larger heights
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        priority_queue<int> maxBricks;
        int i=0, diff;
        
        for(i=0; i<heights.size()-1; i++)
        {
            diff = heights[i+1]-heights[i];
            
            if(diff<=0) 
                continue;
            
            bricks -= diff;
            maxBricks.push(diff);
            
            if(bricks<0)
            {
                bricks += maxBricks.top();
                maxBricks.pop();
                ladders--;
            }
            
            if(ladders<0)
                return i;
        }
        return i;
    }
};