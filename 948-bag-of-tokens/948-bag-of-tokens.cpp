class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int i=0, j=tokens.size()-1, score=0, maxi=0, k=0;
        while(i<=j)
        {
            if(tokens[i]<=power)
            {
                score+=1;
                power-=tokens[i];
                i++;
            }
            else if(score>=1)
            {
                score-=1;
                power+=tokens[j];
                j--;
            }
            else
                break;
            
            maxi=max(maxi, score);
        }
        return maxi;
    }
};