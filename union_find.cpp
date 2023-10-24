class UnionFind{
    private:
        unordered_map<int, int> father;
        unordered_map<int, int> sizeOfSet;
        int numOfSet;
    public:
        UnionFind() {
            numOfSet = 0;
        }
    
        void add(int x) {
            if (father.find(x) != father.end()) return;
            father[x] = -1;
            sizeOfSet[x] = 1;
            numOfSet++;
        
        }
        // return x for input x if the root is default, else return rootX
        // return -1 if x is not in the graph
        int find(int x) {
             if (father.find(x) == father.end()) return -1;
            int root = x;
            while (father[root] != -1) {
                root = father[root];
            }
            while (x != root) {
                int original = father[x];
                father[x] = root;
                x = original;
            }
            return root;
        }
        

        void merge(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            // if both have default root value, then rootX = x and rootY = y
            if (rootX != rootY) {
                father[rootX] = rootY;
                numOfSet--;
                sizeOfSet[rootY] = sizeOfSet[rootX] + sizeOfSet[rootY];
            }

         }
    
        bool isConnected(int x, int y) {
            return find(x) == find(y);
        }
    
        int getSize(int x) {
            int root = find(x);
            return sizeOfSet[root];
        }
    
        int getNum(){
            return numOfSet;
        }
    
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        auto uf = UnionFind();
        int count = 0;
        for (auto &edge: edges) {
            uf.add(edge[0]);
            uf.add(edge[1]);
            uf.merge(edge[0], edge[1]);
        }
        // add single node to graph
        for (int i = 0; i < n; i++) {
            if (uf.find(i) == -1) {
                uf.add(i);
            }
        }
        
        for (int i = 0; i < n; i++) {
            count += n - uf.getSize(i);   
        }
        return count/2;
            
    }
};