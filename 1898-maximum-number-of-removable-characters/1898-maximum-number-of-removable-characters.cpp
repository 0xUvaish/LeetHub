class Solution {
public:
    bool isPossible(string s, string p, vector<int>& v, int k){
        
        int eliminate[100001]={0};
        
        for(int i=0;i<k;i++)
            eliminate[v[i]]=1;
        
        int i=0,j=0;
        int n1=s.length();
        int n2=p.length();
        
        while(i<n1 && j<n2)
        {
            if(eliminate[i]==1)
                i++;
            
            else if(s[i]==p[j])
            {
                i++;
                j++;
            }
            else
                i++;
        }
        
    return j==n2;
        
    }
    
    
    int maximumRemovals(string s, string p, vector<int>& removable) 
    {
        int l=0,r=removable.size();
        int ans=0;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isPossible(s,p,removable,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        
        return ans;
        
    }
};