class Solution {
public:
	int findUnsortedSubarray(vector<int>& A)
    {
		int n=A.size();
		int beg = 2, end = 1, miniRight = A[n-1], maxLeft = A[0];
        
		for (int i=1;i<n;i++) 
        {
			maxLeft = max(maxLeft, A[i]);
			miniRight = min(miniRight, A[n-1-i]);
            
			if (A[i] < maxLeft)
                end = i;
            
			if (A[n-1-i] > miniRight)
                beg = n-1-i; 
		}
        
	return end - beg + 1;
	}
};