class Solution {
public:
    string predictPartyVictory(string senate) {
        int r=0,d=0,n=senate.length();
        for (int i=0;i<n;i++){
            if(senate[i]=='R') r++;
            else d++;
        }
        int rc=0,dc=0,i=0;
        while (r>0 && d>0) {
            if (senate[i] == 'R' && rc > 0) { 
                rc--; 
                senate[i]='M'; 
                r--;
            }
            else if (senate[i] == 'D' && dc > 0) { 
                dc--; 
                senate[i]='M'; 
                d--;
            }
            else if(senate[i] == 'R') dc++;
            else if(senate[i] == 'D') rc++;
            i=(i+1)%n;
        }
        return r>0?"Radiant":"Dire";
    }
};