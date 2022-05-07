class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-3;i++) //4 sum
         {
            if(i==0 || nums[i]!=nums[i-1])                  //a repetition
             {
                
                int a=i;
                for(int j=a+1;j<n-2;j++)  //3 Sum
                    {
                        if(j==a+1 || nums[j]!=nums[j-1])     //b repetition
                        {
                             int b=j;
                             int c=j+1;
                             int d=n-1;

                            while(c<d)  //2 Sum
                            {
                              long long int sum=nums[a]*1ll+nums[b]*1ll+nums[c]*1ll+nums[d]*1ll;

                                if(sum==target)
                                {
                                    res.push_back({nums[a], nums[b], nums[c], nums[d]});

                                    while(c<d && nums[c]==nums[c+1])  //c repetition
                                        c++;
                                    while(c<d && nums[d]==nums[d-1])  //d repetition
                                        d--;

                                    c++;
                                    d--;
                                }
                                else if(sum<target)
                                    c++;
                                else
                                    d--;
                            }
                        }
                    }
                }
            }    
        return res;
    }
};