// https://leetcode.com/problems/design-hashmap/
#include <vector>
#include <list>
using namespace std;

class MyHashMap {
    vector<list<pair<int, int>>> table;
    const int MOD = 2069;
public:
    MyHashMap(){
        table.resize(MOD);
    }
    
    void put(int key, int value) {
        int hash_key = key % MOD;
        for (auto &p: table[hash_key]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[hash_key].emplace_back(key, value);
    }
    
    int get(int key) {
        int hash_key = key % MOD;
        for (auto &[k, v]: table[hash_key]) {
            if (k == key)
                return v;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash_key = key % MOD;
        for (auto it = table[hash_key].begin(); it != table[hash_key].end(); ++it) {
            if (it->first == key) {
                table[hash_key].erase(it);
                return;
            }
        }
        
    }
};

