class Solution {
public:
    int total=0;
    array<int,4> abcd; // 4 sides sum. 
    bool sets(vector<int> &arr,int i){  // Optimising O(4^N) TLE approach with pruning and Optimisations.
        if(i==arr.size()){  // BASE
            for(int i=0;i<=3;i++)if(abcd[i]!=total)return 0;
            return 1;
        }
        
        for(int j=0;j<=3;j++){
            
            int k=j-1;
            while(k>=0){  //Optimisation II, 100 ms improvement, but not enough to remove TLE..
                if(abcd[j]==abcd[k])break;
                k--;
            }
            if(k!=-1)continue;
            
            if(abcd[j]+arr[i]>total)continue; //Optimisation I(when sorting input arr[] in decreasing order) removed TLE.
          
            abcd[j]+=arr[i];
            if(sets(arr,i+1))return 1; //implementation optimisation/pruning, no need to backtrack if found valid solution.
            abcd[j]-=arr[i]; // backtracking.
        }
        return 0;
    }
    bool makesquare(vector<int>& matchsticks) {
        for(int i=0;i<matchsticks.size();i++)total+=matchsticks[i];
        if((total%4!=0)||(matchsticks.size()<4))return 0;// pruning I.
        total/=4;
        if(*max_element(matchsticks.begin(),matchsticks.end())>total)return 0; // pruning II.
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());//Optimisation I-see above(sorting input arr[] in decreasing order) removed TLE.
        return sets(matchsticks,0);
    }
};