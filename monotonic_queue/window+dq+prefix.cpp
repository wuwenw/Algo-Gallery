// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        using ll = long long;
        int n = nums.size();
        int left = 0, res = n + 1;
        deque<int> dq;
        vector<ll> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int i = 0; i <= n; i++) {
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && prefix[i] <= prefix[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res > n ? -1 : res;
    }
};