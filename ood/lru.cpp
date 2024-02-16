// https://leetcode.com/problems/lru-cache/
class LRUCache {
    int size;
    unordered_map<int, list<pair<int, int>>::iterator> dict;
    list<pair<int, int>> kv;
public:
    LRUCache(int capacity) {
        size = capacity;
    }

    void update(int k, int v) {
        kv.push_back({k, v});
        dict[k] = --kv.end();
    }
    
    int get(int key) {
        if (!dict.contains(key)) return -1;
        auto it = dict[key];
        int val = it->second;
        kv.erase(it);
        update(key, val);
        return val;
    }
    
    void put(int key, int value) {
        if (size < 0) return;
        if (dict.contains(key)) {
            kv.erase(dict[key]);
            update(key, value);
            return;
        }
        if (dict.size() == size) {
            int evict_key = kv.front().first;
            kv.erase(kv.begin());
            dict.erase(evict_key);
        }
        update(key, value);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */