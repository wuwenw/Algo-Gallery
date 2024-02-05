// 1143
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // from back
        // string s and t
        // if s[i] == t[j] -> dp(i, j) = dp(i - 1, j - 1) + 1
        // if s[t] != t[j] -> dp(i, j) = max(dp(i - 1, j), dp(i, j - 1))
        int m = text1.size(), n = text2.size();
        int prev = 0;
        vector<int> dp(n + 1);

        for (int i = 0; i < m; i++) {
            prev = 0;
            for (int j = 0; j < n; j++) {
                int tmp = dp[j + 1];
                if (text1[i] == text2[j])
                    dp[j + 1] = prev + 1;
                else
                    dp[j + 1] = max(dp[j + 1], dp[j]);
                prev = tmp;
            }
        }

        return dp[n];
    }
};

// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         // from back
//         // string s and t
//         // if s[i] == t[j] -> dp(i, j) = dp(i - 1, j - 1) + 1
//         // if s[t] != t[j] -> dp(i, j) = max(dp(i - 1, j), dp(i, j - 1))
//         int m = text1.size(), n = text2.size();
//         vector<vector<int>> memo(m, vector<int>(n, -1));
//         function<int(int, int)> dp = [&](int i, int j) {
//             if (i < 0 ||  j < 0)
//                 return 0;
            
//             if (memo[i][j] != -1)
//                 return memo[i][j];
//             if (text1[i] == text2[j])
//                 memo[i][j] = dp(i - 1, j - 1) + 1;
//             else
//                 memo[i][j] = max(dp(i - 1, j), dp(i, j - 1));
//             return memo[i][j];
//         };

//         return dp(m - 1, n - 1);
//     }
// };
