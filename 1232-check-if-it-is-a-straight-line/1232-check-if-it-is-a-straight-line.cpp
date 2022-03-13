class Solution {
public:
bool checkStraightLine(vector<vector<int>>& coordinates){
        vector<int> first = coordinates[0], second = coordinates[1];
    
        int dX = first[0] - second[0], dY = first[1] - second[1]; 
    
        for(auto i: coordinates)
            if(dX * (first[1] - i[1]) != dY * (first[0] - i[0]))
                return false;
    
        return true;
    }
};