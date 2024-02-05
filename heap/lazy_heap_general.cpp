#include <vector>
#include <unordered_map>
#include <queue>
#include <functional>

using namespace std;

template<typename Comp>
struct LazyHeap {
    priority_queue<int, vector<int>, Comp> pq;
    unordered_map<int, int> counts;
    size_t heap_size = 0;

    void push(int num) {
        pq.push(num);
        ++heap_size;
    }

    void pop() {
        cleanTop();
        if (!pq.empty()) {
            pq.pop();
            --heap_size;
        }
        cleanTop();
    }

    void remove(int num) {
        ++counts[num];
        --heap_size;
        cleanTop();
    }

    int top() {
        return pq.top();
    }

    size_t size() {
        return heap_size;
    }

private:
    void cleanTop() {
        // Clean the top element only if necessary, i.e., when the top element has been marked for removal
        while (!pq.empty() && counts[pq.top()] > 0) {
            counts[pq.top()]--;
            pq.pop();
        }
    }
};

struct Item{
    int val;
    bool deleted;
};


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        using ptr = Item*;
        unordered_map<int, Item> items;

        auto max_comp = [](const auto &ptr1, const auto &ptr2) {
            return ptr1->second.val < ptr2->second.val;
        };

        auto min_comp = [](const auto &ptr1, const auto &ptr2) {
            return ptr1->second.val > ptr2->second.val;
        };

        priority_queue<ptr, vector<ptr>, decltype(max_comp)> left(max_comp);
        priority_queue<ptr, vector<ptr>, decltype(min_comp)> right(min_comp);
        int left_size = 0, right_size = 0;
        vector<double> res;

        auto rebalance = [&]() {
            while (right_size > left_size + 1) {
                left.push(right.top());
                right.pop();
            }
            while (right.size() < left.size()) {
                right.push(left.top());
                left.pop();
            }
            while (!left.empty() && left.top()->deleted) {
                left.pop();
            }
            while (!right.empty() && right.top()->deleted) {
                right.pop();
            }
        };

        auto addNum = [&](int i) {
            int num = nums[i];
            items[i] = {num, false};
            if (right_size != 0 && num >= right.top()->val)
                right.push(&items[i]);
            else
                left.push(&items[i]);
            rebalance();
        };

        auto removeNum = [&](int i) {
            int num = nums[i];
            items[i].deleted = true;
            if (num >= right.top()->val)
                right_size--;
            else
                left_size--;
            while (!left.empty() && left.top()->deleted) {
                left.pop();
            }
            while (!right.empty() && right.top()->deleted) {
                right.pop();
            }
            rebalance();
        };

        for (int i = 0; i < nums.size(); ++i) {
            addNum(nums[i]);

            if (i >= k - 1) {
                if (left.size() == right.size())
                    res.push_back(0.5 * ((double)left.top()->val + right.top()->val));
                else
                    res.push_back(right.top()->val);

                removeNum(nums[i - k + 1]);
            }
        }
    
        return res;
    }
};
