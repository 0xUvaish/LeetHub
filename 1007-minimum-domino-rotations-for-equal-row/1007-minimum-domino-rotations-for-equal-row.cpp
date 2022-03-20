class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       
        int mini=INT_MAX;
        int a = tops[0];
        int b = bottoms[0];
        int count=0;
        int n = tops.size(),i=0;
        while(i<n)
        {
            if(tops[i] != a)
            {
                if(bottoms[i] == a)
                    count++;
                else
                    break;
            }
            
        i++;
            
        }
        if(i==n)
            mini = min(mini, count);
        i=0,count=0;
        
        while(i<n)
        {
            if(tops[i] != b)
            {
                if(bottoms[i] == b)
                    count++;
                else
                    break;
            }
            
        i++;
            
        }  
        if(i==n)
            mini = min(mini, count);
        i=0,count=0;
        while(i<n)
        {
            if(bottoms[i] != a)
            {
                if(tops[i] == a)
                    count++;
                else
                    break;
            }
        i++;
        }
               
        if(i==n)
            mini = min(mini, count);
        i=0,count=0;
            while(i<n)
        {
            if(bottoms[i] != b)
            {
                if(tops[i] == b)
                    count++;
                else
                    break;
            }
        i++;
        }
        if(i==n)
            mini = min(mini, count);
        
return mini==INT_MAX ? -1: mini;
    }
};