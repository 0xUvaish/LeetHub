class Solution {
public:
	bool areAlmostEqual(string s1, string s2) {
	
    if(s1==s2)
        return true;
        
	vector<int>v;
        
	for(int i=0;i<s1.size();i++)
        if(s1[i]!=s2[i])
            v.push_back(i);
        
	if(v.size()==2)
        swap(s1[v[0]],s1[v[1]]);
        
	return s1==s2;
        
	}
};