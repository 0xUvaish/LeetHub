class Solution {
public:
	bool is_satisfying(vector<int>& piles,int k,int h)
    {
		int s=0;
		for(int v:piles) 
            s+=ceil((v*1.0)/k);
        
		return s<=h;
	}
    
	int minEatingSpeed(vector<int>& piles, int h) 
    {
		int l=1,r=0,k=0,res=0;
        
		for(int v:piles) 
            r=max(r,v);
        
		while(l<=r)
        {
			k=l+(r-l)/2;
            
			if(is_satisfying(piles,k,h))
            {
				res=k;
				r=k-1;
			}
			else l=k+1;
		}
        
	return res;
	}
};