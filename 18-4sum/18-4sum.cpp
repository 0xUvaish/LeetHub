class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        vector<vector<int>> res;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-3;i++)
            {
            if(i==0 || i>0 && nums[i]!=nums[i-1])
                {
                int a=i;

                for(int j=a+1;j<n-2;j++)
                    {
                        if(j==a+1 || (j>1 && nums[j]!=nums[j-1]))
                        {
                             int b=j;
                             int c=j+1;
                             int d=n-1;

                            while(c<d)
                            {
                              long long int sum=nums[a]*1ll+nums[b]*1ll+nums[c]*1ll+nums[d]*1ll;

                                if(sum==target)
                                {

                                     vector<int>temp;
                                     temp.push_back(nums[a]);
                                     temp.push_back(nums[b]);
                                     temp.push_back(nums[c]);
                                     temp.push_back(nums[d]);

                                     res.push_back(temp);

                                    while(c<d && nums[c]==nums[c+1]) c++;
                                    while(c<d && nums[d]==nums[d-1]) d--;

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