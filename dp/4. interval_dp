// 516
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        // dp(i, j) = dp(i + 1, j - 1) + 2 if s[i] == s[j]
        //            max(dp(i + 1, j), dp(i, j - 1)) if s[i] != s[j]
        //            0 if i > j
        //            1 if i == j
        int n = s.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = 1;
            int prev = 0;
            for (int j = i + 1; j < n; j++) {
                int tmp = dp[j];
                if (s[i] == s[j])
                    dp[j] = prev + 2;
                else
                    dp[j] = max(dp[j - 1], dp[j]);
                prev = tmp;
            }
        }

        return dp[n - 1];
    }
};

// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         // dp(i, j) = dp(i + 1, j - 1) + 2 if s[i] == s[j]
//         //            max(dp(i + 1, j), dp(i, j - 1)) if s[i] != s[j]
//         //            0 if i > j
//         //            1 if i == j
//         int n = s.size();
//         vector<vector<int>> dp(n, vector<int>(n));
//         for (int i = n - 1; i >= 0; i--) {
//             dp[i][i] = 1;
//             for (int j = i + 1; j < n; j++) {
//                 if (s[i] == s[j])
//                     dp[i][j] = dp[i + 1][j - 1] + 2;
//                 else
//                     dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
//             }
//         }

//         return dp[0][n - 1];
//     }
// };

// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         // dp(i, j) = dp(i + 1, j - 1) + 2 if s[i] == s[j]
//         //            max(dp(i + 1, j), dp(i, j - 1)) if s[i] != s[j]
//         //            0 if i > j
//         //            1 if i == j
//         int n = s.size();
//         vector<vector<int>> memo(n, vector<int>(n, -1));
//         function<int(int, int)> dp = [&] (int i, int j) {
//             if (i > j) 
//                 return 0;
//             if (i == j)
//                 return 1 ;
//             if (memo[i][j] != -1)
//                 return memo[i][j];
//             if (s[i] == s[j])
//                 return memo[i][j] = dp(i + 1, j - 1) + 2;
//             return memo[i][j] = max(dp(i + 1, j), dp(i, j - 1));
//         };

//         return dp(0, n - 1);
//     }
// };

// 1039
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

// class Solution {
// public:
//     int minScoreTriangulation(vector<int>& values) {
//         int n = values.size();

//         vector<vector<int>> memo(n, vector<int>(n, -1));
//         function<int(int, int)> dp = [&](int i, int j) {
//             if (i == j - 1)
//                 return 0;
//             if (memo[i][j] != -1)
//                 return memo[i][j];
//             memo[i][j] = INT_MAX;
//             for (int k = i + 1; k < j; k++) {
//                 memo[i][j] = min(memo[i][j], dp(i, k) + dp(k, j) + values[i] * values[k] * values[j]);
//             }
//             return memo[i][j];
//         };

//         return dp(0, n - 1);
//     }
// };


