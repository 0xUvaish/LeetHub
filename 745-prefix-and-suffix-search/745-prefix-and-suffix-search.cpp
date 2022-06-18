struct Node {
    Node* arr[27];
    int index = -1;
    
    bool contains(char ch) {
        return arr[ch-'a'] != NULL;
    }
    
    void put(char ch, Node* newNode) {
        arr[ch-'a'] = newNode;
    }
    
    Node* getNext(char ch) {
        return arr[ch-'a'];
    }
    
    void setIndex(int idx) {
        index = idx;
    }
    
    int getIndex() {
        return index;
    }
};

class WordFilter {
    Node* trie;
public:
    
    void insert(Node* root, string& s, int idx) {
        for(auto& ch : s) {
            if(!root->contains(ch)) {
                root->put(ch, new Node());
            }
            root = root->getNext(ch);
            root->setIndex(idx);
        }
    }
    
    WordFilter(vector<string>& words) {
        trie = new Node();
        
        int idx = 0;
        string s = "";
        
        for(auto& word : words) {
            s = "{" + word;
            insert(trie, s, idx);
            
            for(int i=word.size()-1; i>=0; i--) {
                s = word[i] + s;
                insert(trie, s, idx);
            }
            
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        
        Node* temp = trie;
        
        string match = suffix + "{" + prefix;
        
        for(auto& ch : match) {
            if(!temp || !temp->contains(ch)) return -1;
            temp = temp->getNext(ch);
        }
        
        return temp->getIndex();
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */