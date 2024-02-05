// https://leetcode.com/problems/target-sum/
class Solution {
    // 0-1 背包问题
    // 选 或者 不选，只能选一次
    // Given a list of weights and values, choose items up to the capacity
    // at most capacity -> how many ways/max value
    // excatly capacity -> how many ways/max value/min value
    // at least capacity -> how many ways/min value

    // top down
    int zero_one_knapsack(vector<int>& weights, vector<int>& values, int capacity) {
        int n = weights.size();

        vector<vector<int>> memo(n, vector<int>(capacity + 1, -1));
        function<int(int, int)> dp = [&](int i, int capacity) {
            if (i < 0)
                return 0;
            if (memo[i][capacity] != -1)
                return memo[i][capacity];
            if (capacity < weights[i])
                return dp(i - 1, capacity);
            // dp(i - 1, capacity) -> skip current item
            // dp(i - 1, capacity - weights[i]) + values 
            // -> get current item, reduce capacity and get value
            memo[i][capacity] = max(dp(i - 1, capacity), dp(i, capacity - weights[i]) + values[i]);
            return memo[i][capacity];
        };

        return dp(n - 1, capacity);
    }

    // bottom up
        int zero_one_knapsack_bottom_up(vector<int>& weights, vector<int>& values, int capacity) {
            int n = weights.size();

            vector<vector<int>> dp(n + 1, vector<int>(capacity + 1));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < capacity + 1; j++) {
                    if (j < weights[i])
                        dp[i + 1][j] = dp[i][j];
                    else
                        dp[i + 1][j] = max(dp[i][j], dp[i][j - weights[i]] + values[i]);
                }
            }
            return dp[n][capacity];
    }

    // bottom up optimization
    int zero_one_knapsack_bottom_up1(vector<int>& weights, vector<int>& values, int capacity) {
        int n = weights.size();

        vector<vector<int>> dp(2, vector<int>(capacity + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < capacity + 1; j++) {
                if (j < weights[i])
                    dp[(i + 1) % 2][j] = dp[i % 2][j];
                else
                    dp[(i + 1) % 2][j] = max(dp[i % 2][j], dp[i % 2][j - weights[i]] + values[i]);
            }
        }
        return dp[n % 2][capacity];
    }

    // bottom up optimization 2
    int zero_one_knapsack_bottom_up2(vector<int>& weights, vector<int>& values, int capacity) {
        int n = weights.size();

        vector<int> dp(capacity + 1);
        for (int i = 0; i < n; i++) {
            for (int j = capacity; j >= weights[i]; j--) {
                // from back
                // since dp[j] = max(previous dp[j], previous dp[j - weights[i]] + values[i])
                dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
            }
        }
        return dp[capacity];
    }



    int n;
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        target += sum;
        // No way to get negative (t + s) or an odd result from 2p
        if (target < 0 || target % 2 == 1)
            return 0;
        target /= 2;
        n = nums.size();

        // dp from back using one array
        // since nums[j] depends on nums[j - num]  
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int num : nums) {
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] + dp[j - num];
            }
        }
            
        return dp[target];
    }
        // bottom up with space optimization
    //     int findTargetSumWays(vector<int>& nums, int target) {
    //         // positive sums -> p
    //         // sum - p -> sum of numbers that will be negative
    //         // p - (sum - p) = res == target
    //         // 2p - s == target
    //         // p = (t + s) / 2;
    //         // choose n numbers sum to (t + s) / 2;
    //         int sum = accumulate(nums.begin(), nums.end(), 0);
    //         target += sum;
    //         // No way to get negative (t + s) or an odd result from 2p
    //         if (target < 0 || target % 2 == 1)
    //             return 0;
    //         target /= 2;
    //         n = nums.size();

    //         vector<vector<int>> dp(2, vector<int>(target + 1, 0));
    //         dp[0][0] = 1;
    //         for (int i = 0; i < n; i++) {
    //             for (int j = 0; j < target + 1; j++) {
    //                 if (j < nums[i])
    //                     dp[(i + 1) % 2][j] = dp[i % 2][j];
    //                 else
    //                     dp[(i + 1) % 2][j] = dp[i % 2][j] + dp[i % 2][j - nums[i]];
    //             }
    //         }
            
    //     return dp[n % 2][target];
    // }
    // bottom up dp
    //     int findTargetSumWays(vector<int>& nums, int target) {
    //         // positive sums -> p
    //         // sum - p -> sum of numbers that will be negative
    //         // p - (sum - p) = res == target
    //         // 2p - s == target
    //         // p = (t + s) / 2;
    //         // choose n numbers sum to (t + s) / 2;
    //         int sum = accumulate(nums.begin(), nums.end(), 0);
    //         target += sum;
    //         // No way to get negative (t + s) or an odd result from 2p
    //         if (target < 0 || target % 2 == 1)
    //             return 0;
    //         target /= 2;
    //         n = nums.size();

    //         vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    //         dp[0][0] = 1;
    //         for (int i = 0; i < n; i++) {
    //             for (int j = 0; j < target + 1; j++) {
    //                 if (j < nums[i])
    //                     dp[i + 1][j] = dp[i][j];
    //                 else
    //                     dp[i + 1][j] = dp[i][j] + dp[i][j - nums[i]];
    //             }
    //         }
            
    //     return dp[n][target];
    // }

    // top down dp
    // int findTargetSumWays(vector<int>& nums, int target) {
    //     // positive sums -> p
    //     // sum - p -> sum of numbers that will be negative
    //     // p - (sum - p) = res == target
    //     // 2p - s == target
    //     // p = (t + s) / 2;
    //     // choose n numbers sum to (t + s) / 2;
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
    //     target += sum;
    //     // No way to get negative (t + s) or an odd result from 2p
    //     if (target < 0 || target % 2 == 1)
    //         return 0;
    //     target /= 2;
    //     n = nums.size();

    //     vector<vector<int>> memo(n, vector<int>(target + 1, -1));
    //     function<int(int, int)> dp = [&nums, &dp, &memo](int i, int t) {
    //         if (i < 0)
    //             return t == 0 ? 1 : 0;
    //         if (memo[i][t] != -1)
    //             return memo[i][t];
    //         // nums[i] is too large
    //         if (t < nums[i])
    //             return dp(i - 1, t);
            
    //         memo[i][t] = dp(i - 1, t) + dp(i - 1, t - nums[i]);
    //         return memo[i][t];
    //     };

    //     return dp(n - 1, target);
    // }

};
