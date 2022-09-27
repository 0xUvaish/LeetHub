class Solution {
public:
    string pushDominoes(string dominoes) {
        string sol = "";
        for (int i=0;i<dominoes.size();i++){
            if (dominoes[i] == '.'){
                int point1 = i-1;
                int point2 = i+1;
                bool stop1= false;
                bool stop2 = false;
                while (true){
                    //cout <<point1 <<" " << point2 <<endl;
                    if (point1 < 0) stop1 = true;
                    if (point2 >dominoes.size()-1) stop2= true; 
                    if (!stop2) if (dominoes[point2] == 'R') stop2 = true;
                    if (!stop1) if (dominoes[point1] == 'L') stop1 = true;
                    
                    if (stop1 && stop2) break;
                    
                    if (!stop1 && !stop2) if(dominoes[point2] == 'L' && dominoes[point1] == 'R') {sol+='.';break;}
                     if (!stop2) if (dominoes[point2]=='L' && !stop2) {sol+='L';break;}
                     if (!stop1) if (dominoes[point1]=='R' && !stop1) {sol+='R';break;}
                    point1--;
                    point2++;
                }
                
            }
            if (sol.size()!= i+1)
                sol+= dominoes[i];
        }
        return sol;
        
    }
};