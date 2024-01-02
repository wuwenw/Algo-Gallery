class TrieNode {
      public:
        vector<TrieNode*> children;
        int is_word;
        TrieNode() {
            children = vector<TrieNode*>(26, nullptr);
            is_word = false;
        }
    };

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if(node->children[word[i] - 'a'] == nullptr) {
                node->children[word[i] - 'a'] = new TrieNode();
            }
            node = node->children[word[i] - 'a'];
        }
        node->is_word = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            if(node->children[word[i] - 'a'] == nullptr) {
                return false;
            }
            node = node->children[word[i] - 'a'];
        }
        return node->is_word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            if(node->children[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            node = node->children[prefix[i] - 'a'];
        }
        return true;
    }
    private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */