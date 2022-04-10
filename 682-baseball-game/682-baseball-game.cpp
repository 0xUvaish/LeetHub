class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum=0;
        vector<int>v;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="D")
            {
                int x=v[v.size()-1]*2;
                v.push_back(x);
            }
            else if(ops[i]=="C")
                v.pop_back();
            
            else if(ops[i]=="+")
            {
                int x=v.size()-1;
                int y=v[x]+v[x-1];
                v.push_back(y);
            }
            else
                v.push_back(stoi(ops[i]));
        }
        
        for(int i:v)
            sum+=i;
        
        
        return sum;
    }
};