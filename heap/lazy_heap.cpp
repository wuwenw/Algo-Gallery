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


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        LazyHeap<less<int>> left; // Max heap for the left side
        LazyHeap<greater<int>> right; // Min heap for the right side
        vector<double> res;

        auto rebalance = [&]() {
            while (right.size() > left.size() + 1) {
                left.push(right.top());
                right.pop();
            }
            while (right.size() < left.size()) {
                right.push(left.top());
                left.pop();
            }
        };

        auto addNum = [&](int num) {
            if (right.size() != 0 && num >= right.top())
                right.push(num);
            else
                left.push(num);
            rebalance();
        };

        auto removeNum = [&](int num) {
            if (num >= right.top())
                right.remove(num);
            else
                left.remove(num);
            rebalance();
        };

        for (int i = 0; i < nums.size(); ++i) {
            addNum(nums[i]);

            if (i >= k - 1) {
                if (left.size() == right.size())
                    res.push_back(0.5 * ((double)left.top() + right.top()));
                else
                    res.push_back(right.top());

                removeNum(nums[i - k + 1]);
            }
        }
    
        return res;
    }
};
