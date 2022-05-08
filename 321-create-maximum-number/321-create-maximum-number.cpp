class Solution {
public:
    
    vector<int> maxElement(vector<int> vec,int k,int n)  //Monotonically decreasing vectors (NGL)
    {
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            while(!res.empty() && res.back()<vec[i] && n-i+res.size()>k)
                res.pop_back();
            
            if(res.size()<k)
                res.push_back(vec[i]);
        }
        
        return res;
    }
    
    vector<int> mergeDecr(vector<int> vec1,vector<int> vec2) //Merge in Decr (NOT Exact Merge Procedure)
    {
        
        vector<int> ans;
        while(vec1.size()+vec2.size())
        {
            if(vec1>vec2)
            {
                ans.push_back(vec1[0]);
                vec1.erase(vec1.begin());
            }
            else
            {
                ans.push_back(vec2[0]);
                vec2.erase(vec2.begin());            
            }

        }
        
        return ans;
    }
    
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        
        //Partitioning like Kth elements from sorted array
   
        for(int i=max(0,k-m);i<=min(k,n);i++)
            ans = max(ans,mergeDecr(maxElement(nums1,i,n),maxElement(nums2,k-i,m)));
        
        return ans;
    }

};