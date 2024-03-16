class LFUCache {
    using iter = list<int>::iterator;
    struct Node {
        int key;
        int val;
        int freq;
        iter list_it;
    };
    unordered_map<int, list<int>> freq_keys;
    unordered_map<int, Node> key_nodes;
    int size;
    int min_freq;
    const int starting_freq = 1;

    void updateFreq(Node &node) {
        freq_keys[node.freq].erase(node.list_it);
        if (freq_keys[node.freq].empty()) {
            if (min_freq == node.freq) min_freq++;
        }
        freq_keys[++node.freq].emplace_back(node.key);
        node.list_it = --freq_keys[node.freq].end();
    }

    void evict() {
        auto it = freq_keys[min_freq].begin();
        int key = *it;
        freq_keys[min_freq].erase(it);
        key_nodes.erase(key);
        min_freq = starting_freq;
    }
public:
    LFUCache(int capacity): size(capacity), min_freq(0) {}
    
    int get(int key) {
        auto it = key_nodes.find(key);
        if (it == key_nodes.end()) {
            return -1;
        }
        auto &node = it->second;
        updateFreq(node);
        return node.val;
    }
    
    void put(int key, int value) {
        auto it = key_nodes.find(key);
        if (it != key_nodes.end()) {
            auto &node = it->second;
            updateFreq(node);
            node.val = value;
            return;
        }

        if (key_nodes.size() == size) {
            evict();
        }
        freq_keys[starting_freq].emplace_back(key);
        key_nodes[key] = Node(key, value, starting_freq, --freq_keys[starting_freq].end());
        min_freq = starting_freq;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
