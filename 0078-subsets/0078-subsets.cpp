class Solution {
public:
	void generateSubsets(vector<int>& nums, int currIndex, vector<int>&currSubset, vector<vector<int>>&powerSet)
	   {
		if(currIndex >= nums.size())
        {
			powerSet.push_back(currSubset);
			return;
		}

		int currVal = nums[currIndex];

		currSubset.push_back(currVal);
		generateSubsets(nums, currIndex+1, currSubset, powerSet);
		currSubset.pop_back();
        
		generateSubsets(nums, currIndex+1, currSubset, powerSet);
	}
    
	vector<vector<int>> subsets(vector<int>& nums) 
    {
    
		vector<vector<int>>powerSet;
		vector<int>ArrayList;
		generateSubsets(nums, 0, ArrayList, powerSet);
		return powerSet;

	}
};