// https://leetcode.com/problems/minimum-number-of-coins-for-fruits/
class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        deque<pair<int, int>> dq;
        dq.emplace_front(n + 1, 0);
        for (int i = n; i > 0; i--) {
            while (dq.back().first > 2 * i + 1)
                dq.pop_back();
            int f = prices[i - 1] + dq.back().second;
            while (f <= dq.front().second)
                dq.pop_front();
            dq.emplace_front(i, f);
        }
        return dq.front().second;
    }
};