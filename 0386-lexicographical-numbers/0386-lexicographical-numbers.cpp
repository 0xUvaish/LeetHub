class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if(n==0) return {};
        vector<int> result;
        int current=1; //Initial element
        for(int i=0;i<n;i++){
            result.push_back(current); //Push current to the result.
            current*=10; // Add zero at the end of current.
            while(current>n){ //If current exceeds n.
                current/=10; //Fall back to last element.
                current++; //Get Next in order.
                while(current%10==0) current/=10; //Remove extra trailing zeros.
            }
        }
        return result;
    }
};