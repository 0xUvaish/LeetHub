class Solution {
public:
    
    vector<int> maxelement(vector<int> vec,int k,int n)  //Monotonically decreasing vectors
    {
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            while(!res.empty() && res.back()<vec[i] && n+res.size()-i>k)
                res.pop_back();
            
            if(res.size()<k)
                res.push_back(vec[i]);
        }
        
        return res;
    }
    
    vector<int> maxCombo(vector<int> vec1,vector<int> vec2) //Combine both vectors for overall decreasing (2-pointer)
    {
        vector<int> ans;
        while(vec1.size()+vec2.size())
        {
            vector<int>& now = vec1>vec2?vec1:vec2;
            ans.push_back(now[0]);
            now.erase(now.begin());
        }
        return ans;
    }
    
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<int> ans;
        int n = nums1.size();
        int m = nums2.size();
        
        for(int i=max(0,k-m);i<=min(k,n);i++) //carryout all possibilities of decreasing vectors
            ans = max(ans,maxCombo(maxelement(nums1,i,n),maxelement(nums2,k-i,m)));
        
        return ans;
    }

};