// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/

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
