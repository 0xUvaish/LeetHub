class Solution {
public:
	static bool comp(vector<int>& v1, vector<int>& v2){ // sorting in decreasing order of unitPerBox
        return v1[1]>v2[1];
    }
    int maximumUnits(vector<vector<int>>& boxType, int truckSize) {
        sort(boxType.begin(), boxType.end(), comp);
        int cnt=0; int ans=0;
        
        for(int i=0; i<boxType.size(); i++){
            int numBox=boxType[i][0];  int unitPerBox=boxType[i][1];
            
            if(cnt+numBox<=truckSize){ // we have enough space to fit in all boxes of ith type
                ans+=(numBox)*unitPerBox;
                cnt+=numBox;
            }
            else if(cnt+numBox > truckSize){ // we don't have enough spaces, so take partially
                ans+=(unitPerBox*(truckSize-cnt));
                break;
            }
        }
        return ans;
    }
};