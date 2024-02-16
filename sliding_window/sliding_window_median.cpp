// https://leetcode.com/problems/sliding-window-median/
class Solution {
    struct Item{
        int val = 0;
        bool deleted = false;
        bool is_left = false;
    };
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        using ptr = Item*;
        unordered_map<int, Item> items;

        auto max_comp = [](const auto &ptr1, const auto &ptr2) {
            return ptr1->val < ptr2->val;
        };

        auto min_comp = [](const auto &ptr1, const auto &ptr2) {
            return ptr1->val > ptr2->val;
        };

        priority_queue<ptr, vector<ptr>, decltype(max_comp)> left(max_comp);
        priority_queue<ptr, vector<ptr>, decltype(min_comp)> right(min_comp);
        int left_size = 0, right_size = 0;
        vector<double> res;

        auto cleanup = [&]() {
            while (!left.empty() && left.top()->deleted) {
                left.pop();
            }
            while (!right.empty() && right.top()->deleted) {
                right.pop();
            }
        };

        auto rebalance = [&]() {
            while (right_size > left_size + 1) {
                right.top()->is_left = true;
                left.push(right.top());
                right.pop();
                ++left_size;
                --right_size;
            }
            while (right_size < left_size) {
                left.top()->is_left = false;
                right.push(left.top());
                left.pop();
                --left_size;
                ++right_size;
            }
            cleanup();
        };

        auto addNum = [&](int i) {
            int num = nums[i];
            items[i] = {num, false};
            if (right_size != 0 && num >= right.top()->val) {
                items[i].is_left = false;
                right.push(&items[i]);
                right_size++;
            }
            else {
                items[i].is_left = true;
                left.push(&items[i]);
                left_size++;
            }
            rebalance();
        };

        auto removeNum = [&](int i) {
            int num = nums[i];
            items[i].deleted = true;
            if (items[i].is_left)
                --left_size;
            else
                --right_size;

            cleanup();
            rebalance();
        };

        for (int i = 0; i < nums.size(); ++i) {
            addNum(i);

            if (i >= k - 1) {
                if (left_size == right_size)
                    res.push_back(0.5 * ((double)left.top()->val + right.top()->val));
                else
                    res.push_back(right.top()->val);

                removeNum(i - k + 1);
            }
        }
    
        return res;
    }
};
