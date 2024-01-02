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
    int preorder_index = 0;
    unordered_map<int, int> inorder_map;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_index = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorder_map[inorder[i]] = i;
        }

        return construct(preorder, 0, preorder.size() - 1);
    }

    TreeNode* construct(const vector<int>& preorder, int left, int right)
    {
        if (left > right)
            return nullptr;
        int root_val = preorder[preorder_index++];
        TreeNode* root = new TreeNode(root_val);
        root->left = construct(preorder, left, inorder_map[root_val] - 1);
        root->right = construct(preorder, inorder_map[root_val] + 1, right);
        return root;
    }
};

// divide and conquer
// [3,9,20,15,7], inorder = [9,3,15,20,7]
// in the inorder array, the left of root is it's left substree, right is the right substree
//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    int postorder_index;
    unordered_map<int, int> inorder_map;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postorder_index = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++)
        {
            inorder_map[inorder[i]] = i;
        }

        return construct(postorder, 0, postorder.size() - 1);
    }

    TreeNode* construct(const vector<int>& postorder, int left, int right)
    {
        if (left > right)
            return nullptr;
        
        int root_val = postorder[postorder_index--];
        TreeNode* root = new TreeNode(root_val);

        root->right = construct(postorder, inorder_map[root_val] + 1, right);
        root->left = construct(postorder, left, inorder_map[root_val] - 1);
        return root;
    }
};

// inorder and postorder

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildHelper(nums, 0, nums.size() - 1);
    }

    TreeNode* buildHelper(vector<int>& nums, int left, int right)
    {
        if (left > right)
            return nullptr;
        
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildHelper(nums, left, mid - 1);
        root->right = buildHelper(nums, mid + 1, right);

        return root;
    }
};

// from sorted array
