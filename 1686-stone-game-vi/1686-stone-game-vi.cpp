class Solution {
public:
int stoneGameVI(vector<int>& av, vector<int>& bv)
{
    priority_queue<vector<int>>pq;
    
    for(int i = 0;i< av.size();i++) pq.push({av[i] + bv[i],av[i],bv[i]});
    
    bool turn = false;
    int ali = 0,bob = 0;
    while(!pq.empty())
    {
        if(!turn)
        {
            ali += pq.top()[1];
            pq.pop();
            turn = true;
        }
        else
        {
            bob += pq.top()[2];
            pq.pop();
            turn = false;
        }
    }
    
    if(ali > bob) 
        return 1;
    if(bob > ali) 
        return -1;
    
    return 0;
}
    
};