// https://leetcode.com/problems/diameter-of-binary-tree/
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* cur) {
            if (!cur)
                return -1;
            
            int len_left = dfs(cur->left);
            int len_right = dfs(cur->right);
            ans = max(ans, len_left + len_right + 2);
            return max(len_left, len_right) + 1;
        };
        dfs(root);
        return ans;
    }
};

// https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        function<int(TreeNode*)> dfs = [&](TreeNode* cur) {
            if (!cur)
                return 0;
            int sum_left = max(dfs(cur->left), 0);
            int sum_right = max(dfs(cur->right), 0);
            max_sum = max(max_sum, sum_left + sum_right + cur->val);
            return max(sum_left, sum_right) + cur->val;
        };
        dfs(root);
        return max_sum;
    }
};
