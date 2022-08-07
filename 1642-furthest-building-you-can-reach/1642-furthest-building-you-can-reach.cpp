class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int totalCount = 0;
        priority_queue<int> maxHeap;
        for(int i=0;i<heights.size()-1;i++)
        {
            if(heights[i]>=heights[i+1])
                continue;
            else 
            {
                int diff = heights[i+1]-heights[i];
                //Total count of bricks needed
                totalCount+=diff;
                
                if(ladders!=0) 
                {
                    maxHeap.push(diff);
                
                    if(totalCount>bricks)
                    {
                        totalCount-=maxHeap.top();
                        maxHeap.pop();
                        ladders--;
                    } 
                }
                else
                {
                    if(totalCount>bricks)
                        return i;                
                }
            }
        }

        return heights.size()-1;
    }
};