class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int>ans;
        vector<int>v;
        for(auto x:obstacles){
            if(v.empty()){
                v.push_back(x);
                
            ans.push_back(1);
            }else{
                auto it=upper_bound(v.begin(),v.end(),x)-v.begin();
                if(it==v.size()){
                    v.push_back(x);
                }else{
                    v[it]=x;
                }
             
            ans.push_back(it+1);   
            }
        }
        return ans;
    }
};