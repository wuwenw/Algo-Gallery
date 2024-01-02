class Solution {
public:
    template<bool Zigzag>
    inline TreeNode* popNodeAndPushChildren(deque<TreeNode*>& dq) {
        TreeNode* cur;
        if constexpr(Zigzag) {
            cur = dq.back();
            dq.pop_back();
            if(cur->right) dq.push_front(cur->right);  // Push left before right for Zigzag
            if(cur->left) dq.push_front(cur->left);
        } else {
            cur = dq.front();
            dq.pop_front();
            if(cur->left) dq.push_back(cur->left);  // Push right before left for normal order
            if(cur->right) dq.push_back(cur->right);
        }
        return cur;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        vector<vector<int>> res;
        deque<TreeNode*> dq({root});

        while (!dq.empty()) {
            int size = dq.size();
            vector<int> level_res(size);

            bool isZigzag = res.size() % 2 == 1;

            for (int i = 0; i < size; i++) {
                TreeNode* cur = isZigzag ? popNodeAndPushChildren<true>(dq) : popNodeAndPushChildren<false>(dq);
                level_res[i] = cur->val;
            }

            res.push_back(move(level_res));
        }

        return res;
    }
};
