struct Trie
{
    Trie *children[26];
};

class Solution {
private:
    Trie *root = new Trie();
    bool checkWordNotExists(string w) 
    {
        bool flag = false;
        
        Trie *curr = root;
        int c;
        for(int i = w.size() - 1; i >= 0; i--) 
        {
            c = w[i] - 'a';
            if(!curr->children[c]) 
            {
                flag = true;
                curr->children[c] = new Trie();
            }
            curr = curr->children[c];
        }
        return flag;
    }
    
public:
    int minimumLengthEncoding(vector<string>& words)
    {
        int len = 0;

        sort(begin(words), end(words), [](string a, string b){return b.size() < a.size();});

        for (string w: words)
            if (checkWordNotExists(w)) 
                len += w.size() + 1;
        
        return len;
    }
};