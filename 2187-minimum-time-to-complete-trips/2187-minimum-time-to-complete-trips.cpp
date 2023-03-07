class Solution {
public:
    bool check(long long val,vector<int> &time,int totalTrips){
        long long curr=0;
        for (int i=0; i<time.size(); i++){
            curr+=(val/time[i]);
            if (time[i]>val){
                break;
            }
        }

     return curr>=totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=0,r=1e14+5;

        sort(time.begin(),time.end());

        while (r-l>1){
            long long mid=l+(r-l)/2;

            if (check(mid,time,totalTrips)){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }

        if (check(l,time,totalTrips)){
            return l;
        }
        else{
            return r;
        }
    }
};