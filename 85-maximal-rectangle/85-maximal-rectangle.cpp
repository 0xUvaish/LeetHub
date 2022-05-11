int MAH(vector<int> heights)
{
	vector<int> NSR;
	vector<int> NSL;

	stack<pair<int,int>>st;

	for(int i=heights.size()-1;i>=0;i--)
    {
		if(st.size() == 0)
			NSR.push_back(heights.size());
        
        else  if( st.size() >0 && st.top().first<heights[i])
			NSR.push_back(st.top().second);
        
        else if(st.size()>0 && st.top().first >= heights[i])
        {
			while(st.size()>0 && st.top().first >= heights[i])
				st.pop();
            
			if(st.size() == 0)
				NSR.push_back(heights.size());
            else
				NSR.push_back(st.top().second);
		}
        
		st.push(make_pair(heights[i],i));
	}
    
	reverse(NSR.begin(),NSR.end());

	while(!st.empty())
		st.pop();


	for(int i=0;i<heights.size();i++)
    {
		if(st.empty())
			NSL.push_back(-1);
        
		else if(!st.empty() &&  st.top().first < heights[i])
			NSL.push_back(st.top().second);
        
		else if(!st.empty() && st.top().first >= heights[i])
        {
			while(!st.empty() && st.top().first >= heights[i])
				st.pop();
            
			if(st.empty())
				NSL.push_back(-1);
			else
				NSL.push_back(st.top().second);
		}

		st.push(make_pair(heights[i] , i));
	}

	int maxi = INT_MIN;
	for(int i=0;i<heights.size();i++)
		maxi = max(maxi,((NSR[i] - NSL[i])-1) *heights[i]);
    
	return maxi;
}


class Solution
{
public:
	int maximalRectangle(vector<vector<char>>& matrix) 
    {

	 int ans = INT_MIN;
	 vector<int> v(matrix[0].size(),0);
        
	 for (int i = 0; i < matrix.size(); i++) 
     {
		for (int j = 0; j < matrix[i].size(); j++) 
        {
			if(matrix[i][j] == '1')
				v[j]++;
			else
				v[j] = 0;
		}
		
        int area = MAH(v);
		ans = max(ans, area);

	 }
	return ans;

	}
};