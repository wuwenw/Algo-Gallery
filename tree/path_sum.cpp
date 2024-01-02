// find all path sums equal to target
// https://leetcode.com/problems/path-sum-ii/
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
    vector<vector<int>> paths;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> cur;
        pathSumHelper(root, targetSum, cur);
        return paths;
    }

    void pathSumHelper(TreeNode* root, int targetSum, vector<int> &cur)
    {
        if (root == nullptr)
            return;
        
        targetSum -= root->val;
        cur.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && targetSum == 0)
            paths.push_back(cur);
        else
        {
            pathSumHelper(root->left, targetSum, cur);
            pathSumHelper(root->right, targetSum, cur);
        }

        cur.pop_back();
    }
};

// https://leetcode.com/problems/path-sum-iii/
// prefix sum
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
    int count = 0;
    unordered_map<long, int> sum_counter;
public:
    int pathSum(TreeNode* root, int targetSum) {
        pathSumHelper(root, targetSum, 0l);
        return count;
    }

    void pathSumHelper(TreeNode *root, int targetSum, long curSum)
    {
        if (!root)
            return;
        
        curSum += root->val;

        if (curSum == targetSum)
            count++;
        if (sum_counter.count(curSum - targetSum) > 0)
            count += sum_counter[curSum - targetSum];

        sum_counter[curSum]++;
        pathSumHelper(root->left, targetSum, curSum);
        pathSumHelper(root->right, targetSum, curSum);
        sum_counter[curSum]--;
    }
};
