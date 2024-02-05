// 337

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        function<pair<int, int>(TreeNode*)> dfs = [&](TreeNode* cur) -> pair<int,int> {
            if (!cur)
                return {0, 0};
            auto [rob_left, not_rob_left] = dfs(cur->left);
            auto [rob_right, not_rob_right] = dfs(cur->right);
            int rob_cur = not_rob_left + not_rob_right + cur->val;
            int not_rob_cur = max(rob_left, not_rob_left) + max(rob_right, not_rob_right);
            return {rob_cur, not_rob_cur};
        };
        auto [rob_root, not_rob_root] = dfs(root);
        return max(rob_root, not_rob_root);
    }
};


// 1377
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        int size = edges.size();
        vector<vector<int>> tree(n + 1);
        for (int i = 0; i < size; i++) {
            tree[edges[i][0]].push_back(edges[i][1]);
            tree[edges[i][1]].push_back(edges[i][0]);
        }

        tree[1].push_back(0);
        function<double(int, int, int)> dfs = [&](int i, int fa, int time) -> double {
            if (time == 0)
                return static_cast<int>(i == target);
            if (tree[i].size() == 1)
                return static_cast<int>(i == target);

            for (int child: tree[i]) {
                if (child != fa) {
                    auto prob = dfs(child, i, time - 1);
                    if (prob > 0) {
                        return prob/(tree[i].size() - 1);
                    }
                }
            }
            return 0;

        };

        return dfs(1, 0, t);

    }
};
