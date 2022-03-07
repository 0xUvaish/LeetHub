class Solution {
public:
    double average(vector<int>& salary) {
        double sum=0;
        auto mini = *min_element(salary.begin(),salary.end());
        auto maxi = *max_element(salary.begin(),salary.end());
        for(auto t: salary)
            sum += t;
        
        return (sum-mini-maxi)/(salary.size()-2);
    }
};