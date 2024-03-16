// https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/

class Solution {
public:
    int countSubmatrices(vector<vector<int>> &grid, int k) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        vector<vector<int>> sums(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sums[i + 1][j + 1] = sums[i + 1][j] + sums[i][j + 1] - sums[i][j] + grid[i][j];
                ans += sums[i + 1][j + 1] <= k;
            }
        }
        return ans;
    }
};
