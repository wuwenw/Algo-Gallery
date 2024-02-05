// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
class TreeAncestor {
    vector<vector<int>> pa;
public:
    TreeAncestor(int n, vector<int>& parent) {
        // calculate binary length
        int m = 32 - __builtin_clz(n);
        // 2^0 father is the current father
        pa.resize(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            pa[i][0] = parent[i];
        }

        // try to get 2^(i+1) th 2^i father from 2^i node
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (int p = pa[j][i]; p != -1)
                    pa[j][i + 1] = pa[p][i];
            }
        }
    }
    
    int getKthAncestor1(int node, int k) {
        // delete the lowest bit from k
        // and fetch corresponding parent for it
        for (; k > 0 && node != -1; k &= k - 1) {
            node = pa[node][__builtin_ctz(k)];
        }
        return node;
    }

    int getKthAncestor(int node, int k) {
        int m = 32 - __builtin_clz(k);
        for (int i = 0; i < m; i++) {
            // check ith bit of k
            if ((k >> i) & 1) {
                node = pa[node][i];
                if (node < 0) break;
            }
        }
        return node;
    }
};
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
