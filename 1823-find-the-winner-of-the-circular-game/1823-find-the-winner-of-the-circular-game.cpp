class Solution {
public:
    vector<int>v;
    int recursion(int index,int k){
        if(v.size()==1)
            return v[0];
        index=(index+k-1)%v.size();
        v.erase(v.begin()+index);
       return recursion(index,k);
    }
    int findTheWinner(int n, int k) {
       
        for(int i=0;i<n;i++)
            v.push_back(i+1);
      
    return  recursion(0,k);
    }
};