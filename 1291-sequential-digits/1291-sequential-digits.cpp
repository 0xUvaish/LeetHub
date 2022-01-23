class Solution {
public:
    vector<int> sequentialDigits(int low, int high) 
    {
  
    vector<int> res;        
    string dig ="123456789";

    int lowst=to_string(low).size();
    int upst=to_string(high).size();


    for(int i=lowst;i<=upst;i++)
    { 
        for(int j=0;j<10-i;j++)
        {
            int num =stoi(dig.substr(j,i));
            if(num>=low && num<=high) 
                res.push_back(num);
        }
    }

return res;  
    }
};