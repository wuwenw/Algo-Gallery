// https://leetcode.com/problems/n-queens/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> cols(n);
        vector<bool> path(n), dial1(2 * n - 1), dial2(2 * n - 1);

        function<void(int)> dfs = [&](int i) {
            if (i == n) {
                vector<string> cur(n);
                for (int r = 0; r < n; r++) {
                    cur[r] = string(cols[r], '.') + "Q" + string(n - cols[r] - 1, '.');
                }
                res.push_back(cur);
                return;
            }

            for (int j = 0; j < n; j++) {
                int rc = i - j + n - 1;
                if (!path[j] && !dial1[i + j] && !dial2[rc]) {
                    cols[i] = j;
                    path[j] = dial1[i + j] = dial2[rc] = true;
                    dfs(i + 1);
                    path[j] = dial1[i + j] = dial2[rc] = false;
                }
            }
        };

        dfs(0);
        return res;
    }
};
