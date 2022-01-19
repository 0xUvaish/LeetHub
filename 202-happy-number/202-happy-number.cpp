class Solution {
public:
    bool isHappy(int n) {
        map<int,bool> mp;
        return check(mp,n);
        
    }
    bool check(map<int,bool>mp,int n){
        if(n==1)
            return true;
        if(mp.find(n)!=mp.end())
            return false;
        mp.insert(make_pair(n,true));
        n=update(n);
        return check(mp,n);
            
    }
    int update(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            sum=sum+d*d;
            n/=10;
            
        }
        return sum;
    }
    
};