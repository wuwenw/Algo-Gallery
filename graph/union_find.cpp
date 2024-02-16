
// https://leetcode.com/problems/number-of-provinces/

class Solution {
    struct UnionSet {
        vector<size_t> pa, size;
        int num;
        explicit UnionSet(size_t capacity): pa(capacity), size(capacity, 1), num(capacity) { 
            iota(pa.begin(), pa.end(), 0);
        }
        size_t find(size_t x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
        bool isConnected(size_t x, size_t y) { return find(x) == find(y); }
        void merge(size_t x, size_t y) { 
            x = find(x);
            y = find(y);
            if (x != y) {
                if (x < y) swap(x, y);
                pa[y] = x;
                size[x] += size[y];
                --num;
            }
        }
        // delete and move https://oi-wiki.org/ds/dsu/#%E5%88%A0%E9%99%A4
    };

    struct UnionSet1 {
        unordered_map<int, int> pa;
        int num = 0;
        explicit UnionSet1(size_t capacity) {
            pa.reserve(capacity);
        }
        void add(int x) {
            if (!pa.contains(x)) {
                pa[x] = x;
                ++num;
            }
        }
        int find(int x) {
            // no need if we can ensure all x are added before find()
            if (!pa.contains(x)) {
                add(x);
                return x;
            }
            if (pa[x] == x)
                return x;
            return pa[x] = find(pa[x]);
        }
        bool isConnected(int x, int y) { return find(x) == find(y); }
        void merge(int x, int y) {
            x = find(x);
            y = find(y);
            if (x != y) {
                if (x < y) swap(x, y);
                pa[y] = x;
                --num;
            }
        }
    };

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        size_t n = isConnected.size();
        UnionSet1 us(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j]) {
                    us.add(i);
                    us.add(j);
                    us.merge(i, j);
                }
            }
        }
        
        return us.num;
    }
};
