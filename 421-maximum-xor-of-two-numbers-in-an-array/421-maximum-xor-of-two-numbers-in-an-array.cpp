class Node
{
    public:
    
    Node *links[2];
    
    bool containsKey(int bit)
    {
        return (links[bit]!=NULL);
    }
    
    Node *get(int bit)
    {
        return links[bit];
    }
    
    void put(int bit,Node *node)
    {
        links[bit]=node;
    }
};

class Trie
{
    Node *root;   
    public:
    
    Trie()
    {
        root=new Node();
    }
    void insert(int num)
    {
        Node *temp=root;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(!temp->containsKey(bit))
            {
                temp->put(bit,new Node());
            }
            
            temp=temp->get(bit);
                
        }
    }
    
    int getMax(int num)
    {
        Node *temp=root;
        int maxNum=0;
        for(int i=31;i>=0;i--)
        {
           int bit=(num>>i)&1;
            int opposite=1-bit;
            if(temp->containsKey(opposite))
            {
                maxNum |= (1<<i);
                temp=temp->get(opposite);
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
private : 
public:
    int findMaximumXOR(vector<int>& nums) {
        
        Trie trie;

        vector<int>nums2=nums;
        int n=nums.size();
        int maxVal=0;
        
        for(int i=0;i<n;i++)
            trie.insert(nums[i]);
        
        for(int i=0;i<n;i++)
            maxVal=max(maxVal,trie.getMax(nums2[i]));
        
        return maxVal;
    }
};