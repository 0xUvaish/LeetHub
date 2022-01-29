class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> left,right;
        vector<int> v1,v2;
        
        if(heights.size()==1)
            return heights[0]*1;
        
        for(int i=0;i<heights.size();i++)
        {
            if(left.empty())
                v1.push_back(i);
            
            else
            {
                if(!left.empty() && heights[left.top()]>=heights[i])
                {
                    
                    while(!left.empty() && heights[left.top()]>=heights[i]) 
                        left.pop();
                    
                    if(left.empty())
                        v1.push_back(0);
                    else
                        v1.push_back(left.top()+1);
                }    
                else
                    v1.push_back(i);
            }
            left.push(i);
            v2.push_back(-1);
        }
        
        for(int i=heights.size()-1;i>=0;i--)
        {
            if(right.empty())
                v2[i] =  heights.size()-1;
            else
            {
                if(!right.empty() && heights[right.top()]>=heights[i])
                {
                    while(!right.empty() && heights[right.top()]>=heights[i])
                        right.pop();
                    
                    if(right.empty())
                        v2[i] =  heights.size()-1;
                    else
                        v2[i]=right.top()-1;
                }    
                else
                    v2[i]=i;
            }
            right.push(i);
        }
        
        int maxm = INT_MIN;
        for(int i=0;i<heights.size();i++)
            maxm = max(maxm,heights.at(i)*(v2[i]-v1[i]+1));
        
        return maxm;
            
    }
};