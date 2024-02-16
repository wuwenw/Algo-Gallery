// https://leetcode.com/problems/cherry-pickup-ii/
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        const vector<int> dirs{-1, 0, 1};
        int dp[n][m][m];
        memset(dp, -1, sizeof(dp));
        function<int(int, int, int)> dfs = [&](int i, int j1, int j2) {
            if (j1 < 0 || j2 < 0 || j1 >= m || j2 >= m) {
                return INT_MIN;
            }

            if (i >= n)
                return 0;
            if (dp[i][j1][j2] != -1)
                return dp[i][j1][j2];
            int cur = grid[i][j1];
            if (j1 != j2) cur += grid[i][j2];
            int temp = 0;
            for (int dir: dirs) {
                for (int dir1: dirs) {
                    temp = max(temp, dfs(i + 1, j1 + dir, j2 + dir1));
                }
            }
            cur += temp;
            return dp[i][j1][j2] = cur;
        };

        return dfs(0, 0, m - 1);
    }
};