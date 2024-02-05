// Leetcode 122, 123, 188

// unlimited txns, at most one share of the stock
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // state machine dp
        // 0->not hold, 1->hold
        // status:
        // 0 -> 0: dp(i, 0) = dp(i - 1, 0)
        // 0 -> 1: dp(i, 1) = dp(i - 1, 0) - price
        // 1 -> 0: dp(i, 0) = dp(i - 1, 1) + price
        // 1 -> 1: dp(1, 1): dp(i, 1) = dp(i - 1, 1)
        int n = prices.size();

        vector<int> dp(2);
        dp[0] = 0;
        dp[1] = INT_MIN / 2;
        for (int i = 0; i < n; i++) {
            dp[0] = max(dp[0], dp[1] + prices[i]);
            dp[1] = max(dp[1], dp[0] - prices[i]);
        }

        return dp[0];
    }
};
// top down
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         // state machine dp
//         // 0->not hold, 1->hold
//         // status:
//         // 0 -> 0: dp(i, 0) = dp(i - 1, 0)
//         // 0 -> 1: dp(i, 1) = dp(i - 1, 0) - price
//         // 1 -> 0: dp(i, 0) = dp(i - 1, 1) + price
//         // 1 -> 1: dp(1, 1): dp(i, 1) = dp(i - 1, 1)
//         int n = prices.size();

//         vector<vector<int>> memo(n, vector<int>(2, -1));
//         function<int(int, bool)> dp = [&](int day, bool hold) {
//             if (day < 0)
//                 return hold ? INT_MIN / 2: 0;
//             if (memo[day][hold] != -1)
//                 return memo[day][hold];
//             if (!hold)
//                 memo[day][hold] = max(dp(day - 1, 0), dp(day - 1, 1) + prices[day]);
//             else
//                 memo[day][hold] = max(dp(day - 1, 1), dp(day - 1, 0) - prices[day]);
//             return memo[day][hold];
//         };
//         return dp(n - 1, false);
//     }
// };

// at most 2 transacions
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // state machine dp
        // 0->not hold, 1->hold
        int n = prices.size();

        // 4 -> 0, 1, 2 three states for 2 transactions, and one more position for overflow
        vector<vector<int>> dp(4, vector<int>(2, INT_MIN / 2));
        for (int i = 1; i < 4; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 3; j > 0; j--) {
                dp[j][1] = max(dp[j][1], dp[j][0] - prices[i]);
                dp[j][0] = max(dp[j][0], dp[j - 1][1] + prices[i]);   
            }
        }

        return dp[3][0];
    }
};

// at most k transactions

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // k + 1 states for k transactions
        // 0 -> not hold, 1 -> hold
        vector<vector<int>> dp(k + 2, vector<int>(2, INT_MIN / 2));
        // start with not hold
        // we can do 1 to k + 1 transactions
        // at most k -> states between 1 to k + 1 is 0
        // exactly k -> only state 1 is 0: dp[1][0] = 0 (note off by one)
        // at least k -> at least 0 == no limited, so dp[1][0] = 0 and 
        // when recursive down to k == 1, no more need for j - 1
        for (int i = 1; i < k + 2; i++) {
            dp[i][0] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = k + 1; j > 0; j--) {
                // one txn means one sell 
                dp[j][0] = max(dp[j][0], dp[j - 1][1] + prices[i]);
                dp[j][1] = max(dp[j][1], dp[j][0] - prices[i]);
            }
        }
        return dp[k + 1][0];
    }
};
