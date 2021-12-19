class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        
        int i=0;
        int j=num.size()-1;
        
        vector<int>v(2);
        
        while(i<j)
        {
            if(num[i]+num[j]==t)
            {   v[0]=i+1;
                v[1]=j+1;
             break; 
            }
            else if(num[i]+num[j]>t)
                j--;
            else
                i++;
        }
        
    return v;
        
    }
};