class TrieNode{
public:
    TrieNode* children[26] = {NULL};
    int isWord = false;
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {   //O(N) TIME
        auto cur = root;
        for(auto &w : word){
            int k = w - 'a';
            if(cur->children[k]==NULL){
                cur->children[k] = new TrieNode;
            }
            cur = cur->children[k];
        }
        cur->isWord = true;
    }
    bool searchWord(string &word, int ind, TrieNode* cur){  //O(26^N) TIME
        for(int i = ind; i < word.size(); i++){
            if(word[i]=='.'){
                for(int k = 0 ; k < 26; k++){
                    auto temp = cur->children[k];
                    if(temp!=NULL && searchWord(word, i+1, temp))
                            return true;
                }   
                return false;
            }else{
                int k = word[i] - 'a';
                cur = cur->children[k];   
                if(cur == NULL) return false;
            }
        }
        return cur->isWord;
    }
    bool search(string word) {
        return searchWord(word, 0, root);
    }
    
    ~WordDictionary(){                      
        clear_nodes(root);
    }
    void clear_nodes(TrieNode* root) 
    {
        for(int i = 0; i<26; i++)
            if(root->children[i] != NULL)
                clear_nodes(root->children[i]);
        delete root;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */