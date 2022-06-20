struct Trie
{
    Trie *children[26];
};

class Solution {
private:
    Trie *root = new Trie();
    bool checkWordNotExists(string w) 
    {
        bool res = false;
        
        Trie *curr = root;
        for (int i = w.size() - 1, c; i >= 0; i--) 
        {
            c = w[i] - 'a';
            if (!curr->children[c]) 
            {
                res = true;
                curr->children[c] = new Trie();
            }
            curr = curr->children[c];
        }
        return res;
    }
    
public:
    int minimumLengthEncoding(vector<string>& words)
    {

        int res = 0;

        sort(begin(words), end(words), [](string a, string b){return b.size() < a.size();});

        for (string w: words)
            if (checkWordNotExists(w)) 
                res += w.size() + 1;
        
        return res;
    }
};