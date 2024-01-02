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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root)
            return {};
        
        vector<vector<int>> res;
        unordered_map<int, vector<int>> res_map;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        int size = 0;
        int start = 0, end = 0;

        while (!q.empty())
        {
            size = q.size();
            for (int i = 0; i < size; i++)
            {
                auto [col, node] = q.front();
                q.pop();
                res_map[col].push_back(node->val);
                start = min(start, col);
                end = max(end, col);
                if (node->left)
                    q.push({col - 1, node->left});
                
                if (node->right)
                    q.push({col + 1, node->right});
            }
        }
    
    for (int i = start; i <= end; i++)
    {
        res.push_back(res_map[i]);
    }

    return res;
    }
};
