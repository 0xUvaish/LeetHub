class Solution {
public:
    
    //Method 1: O(n) TC, O(n) SC
//     vector<int> twoSum(vector<int>& nums, int target) {
        
//         vector<int>ans;
//         int n=nums.size();
//         unordered_map<int,int>m;
        
//         for(int i=0;i<n;i++)
//             m.insert({nums[i],i});
        
//         for(int i=0;i<n;i++)
//         {
//            if(m.find(target-nums[i]) != m.end() and i!=m[target-nums[i]])
//            {
//                ans.push_back(i);
//                ans.push_back(m[target-nums[i]]);
//                return ans;
//            }
//         }
        
//        return ans;   
//     }
    
    
    //Method 2: O(n) TC, O(1) SC
    
    vector<int> twoSum(vector<int>& nums, int t) 
    {
       int n=nums.size();
       int l=0, r=n-1;
        
       vector<pair<int,int>> v(n);
        
       // mapping indices
	   for(int i=0;i<n;++i)
            v[i]={nums[i],i};
        
        sort(v.begin(),v.end());
        
        while(l<r)
        {
            int a = v[l].first;
            int b = v[r].first;
            
            if(a+b==t) 
                return {v[l].second, v[r].second}; 
            
            else if(a+b<t)  
                ++l;
            
            else     
                --r;
        }
        
        return {};
	}
    
};