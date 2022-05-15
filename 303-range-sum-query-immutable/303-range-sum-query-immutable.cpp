class NumArray {
public:
  vector<int>* nums;
  NumArray(vector<int>& nums): nums(&nums) {
    for(int i = 1; i < nums.size(); i++) nums[i] += nums[i-1];  
  }

  int sumRange(int left, int right) {
    return left? (*nums)[right] - (*nums)[left-1]: (*nums)[right];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */