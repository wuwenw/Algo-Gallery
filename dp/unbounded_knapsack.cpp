// https://leetcode.com/problems/coin-change/
class Solution {
    // 完全背包问题
    // 可重复选
    int unbounded_knapsack(vector<int>& weights, vector<int>& values, int capacity) {
        int n = weights.size();

        vector<vector<int>> memo(n, vector<int>(capacity + 1, -1));
        function<int(int, int)> dp = [&](int i, int capacity) {
             // return condition based on questions
            if (i < 0)
                return 0;
            if (memo[i][capacity] != -1)
                return memo[i][capacity];
            if (capacity < weights[i])
                return dp(i - 1, capacity);
            // dp(i - 1, capacity) -> skip current item
            // dp(i, capacity - weights[i]) + values 
            // -> get current item, reduce capacity， get value
            // stay with current
            memo[i][capacity] = max(dp(i - 1, capacity), dp(i, capacity - weights[i]) + values[i]);
            return memo[i][capacity];
        };

        return dp(n - 1, capacity);
    }

    int unbounded_knapsack_bottom_up(vector<int>& weights, vector<int>& values, int capacity) {
        int n = weights.size();

         // init dp based on questions
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= capacity; j++) {
                if (j < weights[i])
                    dp[i + 1][j] = dp[i][j];
                else
                    dp[i + 1][j] = min(dp[i][j], dp[i + 1][j - weights[i]] + values[i]);
            }
        }
        return dp[n][capacity];
    }

    // bottom up space optimization
    int unbounded_knapsack_bottom_up2(vector<int>& weights, vector<int>& values, int capacity) {
        int n = weights.size();

         // init dp based on questions
        vector<int> dp(capacity + 1, -1);
        for (int i = 0; i < n; i++) {
            for (int j = weights[i]; j <= capacity; j++) {
                    // simply from the begining
                    // dp[j] == min(previous dp[j], current dp[j - weights[i]] + values[i])
                    dp[j] = min(dp[j], dp[j - weights[i]] + values[i]);
            }
        }
        return dp[capacity];
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> dp(amount + 1, INT_MAX / 2);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        int ans = dp[amount];
        return ans == INT_MAX / 2 ? -1 : ans;
    }
};
