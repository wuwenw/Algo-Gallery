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
    TreeNode* prev = nullptr;
public:
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }

    bool inorder(TreeNode* root)
    {
        if (root == nullptr)
        {
            return true;
        }

        if (!inorder(root->left))
            return false;
        
        if (prev != nullptr && root->val <= prev->val)
        {
            return false;
        }

        prev = root;
        return inorder(root->right);

    }
};

// inorder. keep track of previous val and compare with cur
// https://leetcode.com/problems/validate-binary-search-tree/

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
    TreeNode* x = nullptr;
    TreeNode* y = nullptr;
    TreeNode* prev = nullptr;
public:
    void recoverTree(TreeNode* root) {
        findSwapped(root);
        swap(x, y);
    }

    void findSwapped(TreeNode* root)
    {
        if (root == nullptr)
            return;
        findSwapped(root->left);
        if (prev != nullptr && root->val < prev->val)
        {
            // for the second time, root is too low
            y = root;
            // for the first time, prev is too high
            if (!x)
                x = prev;
            else
                return;
        } 
        prev = root;
        findSwapped(root->right);
    }

    void swap(TreeNode* a, TreeNode *b)
    {
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
};
// recover
