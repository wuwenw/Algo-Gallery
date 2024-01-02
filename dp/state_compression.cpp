class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        int total_states = 1 << n;
        vector<vector<int>> dp(m + 1, vector<int>(total_states, -1));
        dp[0][0] = 0;

        auto isValid = [&](int i, int s) {
            for (int j = 0; j < n; j++) {
                if (s >> j & 1) {
                    if (seats[i][j] == '#')
                        return false;

                    if ((j - 1 >= 0) && (s >> (j - 1) & 1))
                        return false;

                    if ((j + 1 < n) && (s >> (j + 1) & 1))
                        return false;
                }
            }

            return true;
        };

        auto check = [&](int k, int s) {
            for (int j = 0; j < n; j++) {
                if (s >> j & 1) {
                    if (j - 1 >= 0 && k >> (j - 1) & 1)
                        return false;
                    if (j + 1 < n && k >> (j + 1) & 1)
                        return false;
                }
            }
            return true;
        };

        for (int i = 0; i < m; i++) {
            for (int s = 0; s < total_states; s++) {
                // if row i is valid with current state s
                if (isValid(i, s)) {
                    for (int k = 0; k < total_states; k++) {
                        // if previous dp entry dp[i][k] is valid
                        if (dp[i][k] != -1 && check(k, s)) {
                            // transfer from dp[i][k] + current val
                            dp[i + 1][s] = max(dp[i + 1][s], dp[i][k] + __builtin_popcount(s));
                        }
                    }
                }
            }
        }

        return *max_element(dp[m].begin(), dp[m].end());
    }
};

class Solution {
public:
    int maxStudents(vector<vector<char>> &seats) {
        int m = seats.size(), n = seats[0].size();
        vector<int> a(m); // a[i] 是第 i 排可用椅子的下标集合
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (seats[i][j] == '.') {
                    a[i] |= 1 << j;
                }
            }
        }

        vector<vector<int>> f(m, vector<int>(1 << n));
        for (int j = 1; j < (1 << n); j++) {
            int lb = j & -j;
            f[0][j] = f[0][j & ~(lb * 3)] + 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = a[i]; j; j = (j - 1) & a[i]) { // 枚举 a[i] 的子集 j
                f[i][j] = f[i - 1][a[i - 1]]; // 第 i 排空着
                for (int s = j; s; s = (s - 1) & j) { // 枚举 j 的子集 s
                    if ((s & (s >> 1)) == 0) { // s 没有连续的 1
                        int t = a[i - 1] & ~(s << 1 | s >> 1); // 去掉不能坐人的位置
                        f[i][j] = max(f[i][j], f[i - 1][t] + f[0][s]);
                    }
                }
            }
            f[i][0] = f[i - 1][a[i - 1]];
        }
        return f[m - 1][a[m - 1]];
    }
};
