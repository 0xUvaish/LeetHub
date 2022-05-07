class Solution {
public:
    
  int INF = 1e5+5;
  int maxArea(vector<int>& height)
  {
    int n = height.size();
    int left = 0, right = n-1;
    int max_area = -INF;
      
    while(left < right) 
    {
      int least_support = min(height[left],height[right]);
        
      int curr_area = (right-left) * least_support;
      max_area = max(curr_area, max_area);
        
      if(height[left] < height[right]) 
          left++;
      else 
          right--;
    }
      
    return max_area;
  }
};