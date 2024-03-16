// https://leetcode.com/problems/implement-trie-prefix-tree/
class Trie {
    struct Node {
        Node* sons[26]{};
        bool is_word = false;
    };
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string& word) {
        auto cur = root;
        for (char c: word) {
            c -= 'a';
            if (cur->sons[c] == nullptr)
                cur->sons[c] = new Node();
            cur = cur->sons[c];
        }
        cur->is_word = true;
    }
    
    bool search(string& word) {
        auto cur = root;
        for (char c: word) {
            c -= 'a';
            if (cur->sons[c] == nullptr)
                return false;
            cur = cur->sons[c];
        }
        return cur->is_word;
    }
    
    bool startsWith(string& prefix) {
        auto cur = root;
        for (char c: prefix) {
            c -= 'a';
            if (cur->sons[c] == nullptr)
                return false;
            cur = cur->sons[c];
        }
        return true;
    }
private:
    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */