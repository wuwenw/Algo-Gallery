// O(nlogn) total runtime, and log n for each query
class TreeAncestor {
    vector<vector<int>> pa;
    vector<int> depth;
public:
    TreeAncestor(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        // calculate binary length
        int m = 32 - __builtin_clz(n);

        vector<vector<int>> graph(n);
        for (auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        depth.resize(n);
        pa.resize(n, vector<int>(m, -1));
        function<void(int, int)> dfs = [&](int x, int fa) {
            pa[x][0] = fa;
            for (int y: graph[x]) {
                if (y != fa) {
                    depth[y] = depth[x] + 1;
                    dfs(y, x);
                }
            }

        };
        dfs(0, -1);

        // try to get 2^(i+1) th 2^i father from 2^i node
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                if (int p = pa[j][i]; p != -1)
                    pa[j][i + 1] = pa[p][i];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for (; k > 0 && node != -1; k &= k - 1) {
            node = pa[node][__builtin_ctz(k)];
        }
        return node;
    }

    int getLCA(int x, int y) {
        if (depth[x] > depth[y]) {
            swap(x, y);
        }

        y = getKthAncestor(y, depth[y] - depth[x]);

        if (y == x)
            return x;
        
        for (int i = pa.size() - 1; i >=0; i--) {
            int px = pa[x][i], py = pa[y][i];
            if (px != py) {
                x = px;
                y = py;
            }
        }
        return pa[x][0];
    }
};

// O(n) solution
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca;
        findLCA(root, p, q, &lca);
        return lca;
    }

    bool findLCA(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** lca)
    {
        if (!root)
            return false;
        
        int mid = root == p || root == q;
        int left = findLCA(root->left, p, q, lca);
        int right = findLCA(root->right, p, q, lca);
        if (mid + left + right == 2)
            *lca = root;
        return mid + left + right > 0;
    }
};

// below is a binary search tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
