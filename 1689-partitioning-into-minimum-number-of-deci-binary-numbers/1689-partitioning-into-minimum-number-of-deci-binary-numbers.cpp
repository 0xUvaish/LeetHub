class Solution {
public:
    int minPartitions(string n) 
    {
      int maxi = 0,len = n.size();
      for(int i=0;i<len;i++)
      {
        int num = n[i] - 48;        
        if(num==9) 
           return 9;       
      
         if(num>maxi) 
           maxi=num;
       }
      return maxi;                          //return the largest digit as answer

    }
};