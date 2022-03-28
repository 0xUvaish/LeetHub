struct Node
{
    Node *links[2];
    
    bool contains(int bit)
    {
        return links[bit]!=NULL;
    }
    
    Node *get(int bit)
    {
        return links[bit];
    }
    
    void put(int bit, Node *temp){
        links[bit] = temp;
    }  
};

class Trie
{
private: 
    Node *root;
public:
    Trie()
    {
        root = new Node();
    }
    
    void insert(int n)
    {
        Node *temp = root;
        
        for(int i=31; i>=0; i--){
            int bit = (n>>i)&1;
            if(!temp->contains(bit)){
                temp->put(bit, new Node());
            }
            temp=temp->get(bit);
        }
    }
    
    int getMax(int x)
    {
        int maxNum = 0;
        Node *temp = root;
        
        for(int i=31; i>=0; i--)
        {
            int bit = (x>>i)&1;
            if(temp->contains(!bit))
            {
                maxNum = (maxNum) | (1<<i);
                temp=temp->get(!bit);
            }
            else
            {
                temp=temp->get(bit);
            }
        }
        return maxNum;
    }
};

class Solution {
private:
    Trie t;
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size();
        int n = nums.size();
        
        vector<int> ans(q, 0);        
        vector<pair<int, pair<int, int>>> offlineQ;
        
        for(int i=0; i<q; i++)
        {
            int xi = queries[i][0];
            int mi = queries[i][1];
            
            offlineQ.push_back({mi, {xi, i}});
        }
                
        sort(nums.begin(), nums.end());
        sort(offlineQ.begin(), offlineQ.end());
        
        int j=0;
        for(int i=0; i<q; i++)
        {
            int limit = offlineQ[i].first;
            int x = offlineQ[i].second.first;
            int qIdx = offlineQ[i].second.second;
            
            while(j<n and nums[j]<=limit)
            {
                t.insert(nums[j]);
                j++;
            }
            if(j==0)
            {
                ans[qIdx] = -1;
            }
            else
            {
                ans[qIdx] = t.getMax(x);
            }
        }
        return ans;
    }
};