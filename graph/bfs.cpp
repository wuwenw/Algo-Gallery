class Solution {
    const vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int island = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    bfs(grid, visited, i, j);
                    island++;
                }
            }
        }
        return island;
    }

    inline bool boundaryCheck(int i, int j, int m, int n) {
        return i >= 0 && j >= 0 && i < m && j < n;
    }

    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> candidates;
        candidates.push({i, j});
        visited[i][j] = true;

        while (!candidates.empty()) {
            auto cur = candidates.front();
            candidates.pop();

            for (const auto& direction : directions) {
                int next_i = cur.first + direction[0];
                int next_j = cur.second + direction[1];

                if (boundaryCheck(next_i, next_j, m, n) && grid[next_i][next_j] == '1' && !visited[next_i][next_j]) {
                    visited[next_i][next_j] = true;
                    candidates.push({next_i, next_j});
                }
            }
        }
    }
};

// https://leetcode.com/problems/number-of-islands/
