class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        vector<pair<int,int>> vec;
        for(int i=0;i<properties.size();i++) vec.push_back({properties[i][0],properties[i][1]});
        sort(vec.begin(),vec.end());
        int maxx=vec[properties.size()-1].second,maxf=vec[properties.size()-1].first,premax=0,count=0;
        for(int i=properties.size()-2;i>=0;i--)
        {
            if(vec[i].second<maxx && vec[i].first<maxf)
                count++;
            if(vec[i].first==maxf && vec[i].second<premax) count++; 
            if(vec[i].second>maxx)
            {
                if(vec[i].first!=maxf)
                premax=maxx;
                maxx=vec[i].second;
                maxf=vec[i].first;
            }    
        }
        return count;
    }
};