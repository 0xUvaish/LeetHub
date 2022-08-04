class Solution {
public:
    //Linear Eqn in Two Variables
    vector<int> numOfBurgers(int tomato, int cheese) {
        if(tomato>cheese*4 || tomato<2*cheese || tomato%2!=0)
            return {};
        
        return {tomato/2-cheese, cheese*2-tomato/2};
    }
};