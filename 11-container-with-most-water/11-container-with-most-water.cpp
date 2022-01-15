class Solution {
public:
  int INF = 1e5+5;
  int maxArea(vector<int>& height) {
    int left = 0, right = (int) height.size()-1, max_area = -INF;
    while(left < right) {
      int lower_bound = min(height[left],height[right]);
      int curr_area = (right-left) * lower_bound;
      max_area = max(curr_area, max_area);
      if(height[left] < height[right]) left++;
      else right--;
    }
    return max_area;
  }
};