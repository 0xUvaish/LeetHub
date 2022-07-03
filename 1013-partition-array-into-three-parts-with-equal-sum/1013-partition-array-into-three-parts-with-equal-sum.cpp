class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
      int total=0;
        for(auto x: arr)
          total += x;
        
        int req_parts = 3; //Can be generalized
        
        if(total%req_parts!=0)
            return false;
        
        int ind = total/req_parts;
        int part=0;
        int prefixS=0;
        
        for(auto y: arr)
        {
           prefixS += y;
            if(prefixS==(part+1)*ind)
                part++;
        }
        
    return part>=req_parts;
    }
};